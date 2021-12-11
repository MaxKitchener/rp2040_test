/*
 * ****************************************************************************
 * File           :       i2c.cpp
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "i2c.h"


uint tc_i2c::check_address_reserved(uint address)
{
    return (address & 0x78) == 0 || (address & 0x78) == 0x78;
}


tc_i2c::tc_i2c(i2c_inst_t* _i2c, uint _sda_pin, uint _scl_pin, uint _speed)
{
    i2c = _i2c;
    sda_pin = _sda_pin;
    scl_pin = _scl_pin;
    speed = _speed;
}

void tc_i2c::init()
{
    i2c_init(i2c1, speed);

    // setup IO
    gpio_set_function(sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin);
    gpio_pull_up(scl_pin);
    //bi_decl(bi_2pins_with_func(sda_pin, scl_pin, GPIO_FUNC_I2C));
}

void tc_i2c::scan(uint print)
{
    if(print)
    {
        printf("\nI2C Bus Scan\n");
        printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    }

    for (int addr = 0; addr < (1 << 7); ++addr) {
        if (addr % 16 == 0 && print) {
            printf("%02x ", addr);
        }

        // Perform a 1-byte dummy read from the probe address. If a slave
        // acknowledges this address, the function returns the number of bytes
        // transferred. If the address byte is ignored, the function returns
        // -1.

        // Skip over any reserved addresses.
        int ret;
        uint8_t rxdata;
        if (check_address_reserved(addr))
            ret = PICO_ERROR_GENERIC;
        else
            ret = i2c_read_blocking(i2c, addr, &rxdata, 1, false);
        if ( print )
        {
            printf(ret < 0 ? "." : "@");
            printf(addr % 16 == 15 ? "\n" : "  ");
        }
    }
}


void tc_i2c::read(uint8_t address, uint8_t reg, uint8_t* buffer, uint length)
{
    // Set memory pointer in I2C device to desired register
    write(address, &reg, 1);
    // Read back 'length' bytes
    i2c_read_blocking(i2c, address, buffer, length, false);
}

void tc_i2c::write(uint8_t address, uint8_t* buffer, uint length)
{
    i2c_write_blocking(i2c, address, buffer, length, false);
}

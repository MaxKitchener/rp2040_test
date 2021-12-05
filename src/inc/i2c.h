/*
 * ****************************************************************************
 * File           :       i2c.h
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */


#ifndef _I2C_H
#define _I2C_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

class cl_i2c
{
    private:
        i2c_inst_t* i2c;
        uint sda_pin;
        uint scl_pin;
        uint speed;

        uint check_address_reserved(uint address);
    public:
        cl_i2c(i2c_inst_t* _i2c, uint _sda_pin, uint _scl_pin, uint _speed);
        void init();
        void scan(uint print);
        void read(uint address, uint8_t* buf, uint len);
        void write(uint address, uint8_t* buf, uint len);
};

#endif

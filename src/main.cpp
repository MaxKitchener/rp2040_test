/*
 * ****************************************************************************
 * File           :       main.cpp
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#include "tui.h"

#include "gpio.h"
#include "i2c.h"
#include "vt100.h"
#include "vl6108.h"

#define BOOT_DELAY 1500





tc_vt100 terminal;
tc_vl6108 vl6108;

ts_table_entry ts_te_id[] =
{
    {"model id",        &vl6108.id.model_id,            HEX8},
    {"model id",        &vl6108.reg.id_model_id,        HEX8},
    {"model rev",       &vl6108.id.model_rev,           FLOAT},
    {"model rev maj",   &vl6108.reg.id_model_rev_maj,   HEX8},
    {"model rev min",   &vl6108.reg.id_model_rev_min,   HEX8},
    {"module rev",      &vl6108.id.module_rev,          FLOAT},
    {"module rev maj",  &vl6108.reg.id_module_rev_maj,  HEX8},
    {"module rev min",  &vl6108.reg.id_module_rev_min,  HEX8},
    {"date",            &vl6108.id.date,                FLOAT},
    {"time",            &vl6108.id.time,                UINT16},
    {NULL,              NULL,                           STRING}
};

ts_table_entry ts_te_sys[] =
{
    {"mode gpio0",              &vl6108.reg.sys_mode_gpio0,             UINT8},
    {"mode gpio1",              &vl6108.reg.sys_mode_gpio1,             UINT8},
    {"history ctrl",            &vl6108.reg.sys_history_ctrl,           UINT8},
    {"interrupt conf gpio0",    &vl6108.reg.sys_interrupt_config_gpio0, UINT8},
    {"interupt clear",          &vl6108.reg.sys_interrupt_clear,        UINT8},
    {"fresh out of reset",      &vl6108.reg.sys_fresh_out_of_reset,     UINT8},
    {"grouped paramater hold",  &vl6108.reg.sys_grouped_parameter_hold, UINT8},
    {NULL,                      NULL,                                   STRING}
};

tc_table tb_id(&terminal, "ID Info",   ts_te_id, 39, 10);
tc_table tb_sys(&terminal, "Sys Info", ts_te_sys, 39, 10);




/**
 * @brief
 *
 * @return int
 */
int main()
{
    uint counter = 0;
    uint cursor_row = 0;
    uint cursor_collumn = 0;

    stdio_init_all(); // initialise uart
    tc_i2c i2c(i2c_default, PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, 25000);

    gpio[0].init();
    gpio[1].init();
    gpio[2].init();

    i2c.init();
    vl6108.set_i2c(&i2c);

    while(!gpio[2].read())
    {
        gpio[0].write(1);
    }

    sleep_ms(BOOT_DELAY);
    terminal.set_cursor(1, 1);
    terminal.set_window_size(80, 40);
    terminal.clear_screen();
    terminal.clear_terminal();

    terminal.create_window_at_pos(80, 40, "VL6108 I2C Test", 1,1);

    vl6108.get_id_info();
    vl6108.get_sys_info();
    vl6108.get_sysrange_info();

    cursor_row = 4;
    cursor_collumn = 2;

    //terminal.create_window_at_pos(39, 8, "ID Info", cursor_collumn, cursor_row);
    tb_id.print_table_at_pos(cursor_collumn, cursor_row);
    //cursor_collumn = 3;
    //cursor_row = cursor_row + 3;
    //terminal.set_cursor(cursor_collumn, cursor_row++);
    //printf("%-20.20s : 0x%02X", "model id", vl6108.reg.id_model_id);
    //terminal.set_cursor(cursor_collumn, cursor_row++);
    //printf("%-20.20s : %i.%i", "model rev", vl6108.reg.id_model_rev_maj, vl6108.reg.id_model_rev_min);
    //terminal.set_cursor(cursor_collumn, cursor_row++);
    //printf("%-20.20s : %i.%i", "module rev", vl6108.reg.id_module_rev_maj, vl6108.reg.id_module_rev_min);
    //terminal.set_cursor(cursor_collumn, cursor_row++);
    //printf("%-20.20s : %i.%i", "date", vl6108.reg.id_date_hi, vl6108.reg.id_date_lo);
    //terminal.set_cursor(cursor_collumn, cursor_row++);
    //printf("%-20.20s : %i", "time", vl6108.reg.id_time);

    //cursor_row = 14;
    //cursor_collumn = 2;
    //terminal.create_window_at_pos(39, 10, "Sys Info", cursor_collumn, cursor_row);
    cursor_row = 25;
    cursor_collumn = 2;
    tb_sys.print_table_at_pos(cursor_collumn, cursor_row);







    cursor_row = 4;
    cursor_collumn = 41;

    terminal.create_window_at_pos(39, 20, "SysRange Info", cursor_collumn, cursor_row);
    cursor_collumn = 42;
    cursor_row = 7;
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "start", vl6108.reg.sysrange_start);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "thresh high", vl6108.reg.sysrange_thresh_high);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "thresh low", vl6108.reg.sysrange_thresh_low);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "intermeasurement period", vl6108.reg.sysrange_intermeasurement_period);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "max convergance time", vl6108.reg.sysrange_max_convergance_time);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "crosstalk compensation", vl6108.reg.sysrange_crosstalk_compensation_rate);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "crosstalk valid height", vl6108.reg.sysrange_crosstalk_valid_height);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "early convergance estimate", vl6108.reg.sysrange_early_convergance_estimate);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "part to part range offset", vl6108.reg.sysrange_part_to_part_range_offset);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "range ignore valid height", vl6108.reg.sysrange_range_ignore_valid_height);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "range ignore threshold", vl6108.reg.sysrange_range_ignore_thresh);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "max ambient level mult", vl6108.reg.sysrange_max_ambient_level_mult);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "range check enables", vl6108.reg.sysrange_range_check_enables);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "vhv recalibrate", vl6108.reg.sysrange_vhv_recalibrate);
    terminal.set_cursor(cursor_collumn, cursor_row++);
    printf("%-20.20s : %i", "vhv repeat rate", vl6108.reg.sysrange_vhv_repeat_rate);



    while (true)
    {
        gpio[0].write(1);
        gpio[1].write(0);
        sleep_ms(250);
        gpio[0].write(0);
        gpio[1].write(1);
        sleep_ms(250);
        counter++;

        terminal.set_cursor(cursor_collumn,  18);
        terminal.set_colour(RED);
        printf("RunTime : %02i:%02i:%02i", counter/(60*60), (counter/60)%60, counter%60);
        terminal.set_colour(WHITE);

        if(gpio[2].read())
        {
            sleep_ms(250);
            if(gpio[2].read())
            {
                reset_usb_boot(0, 0);
            }
        }
    }
}

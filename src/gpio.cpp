/*
 * ****************************************************************************
 * File           :       gpio.cpp
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */


#include "gpio.h"

tc_pin gpio[] =
{
    { PICO_DEFAULT_LED_PIN,    GPIO_OUT,    0},
    { 15,                      GPIO_OUT,    0},
    { 14,                      GPIO_IN,     2}
};


tc_pin::tc_pin(uint _pin_no, uint _direction, uint _pullup)
{
    pin_no = _pin_no;
    direction = _direction;
    pullup = _pullup;
}

void tc_pin::init()
{
    gpio_init(pin_no);
    gpio_set_dir(pin_no, direction);

    if     (pullup == 1) gpio_pull_up(pin_no);
    else if(pullup == 2) gpio_pull_down(pin_no);
}

uint tc_pin::read()
{
    return(gpio_get(pin_no));
}

void tc_pin::write(uint value)
{
    gpio_put(pin_no, value);
}

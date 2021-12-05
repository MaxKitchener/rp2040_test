#include "pico/stdlib.h"
#include "gpio.h"

cl_pin gpio[] =
{
    { PICO_DEFAULT_LED_PIN,    GPIO_OUT,    0},
    { 15,                      GPIO_OUT,    0},
    { 14,                      GPIO_IN,     1}
};


cl_pin::cl_pin(uint _pin_no, uint _direction, uint _pullup)
{
    pin_no = _pin_no;
    direction = _direction;
    pullup = _pullup;
}

void cl_pin::init()
{
    gpio_init(pin_no);
    gpio_set_dir(pin_no, direction);

    if     (pullup == 1) gpio_pull_up(pin_no);
    else if(pullup == 2) gpio_pull_down(pin_no);
}

uint cl_pin::read()
{
    return(gpio_get(pin_no));
}

void cl_pin::write(uint value)
{
    gpio_put(pin_no, value);
}

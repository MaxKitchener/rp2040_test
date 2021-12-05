#include "pico/stdlib.h"

class cl_gpio
{
    public:
        uint pin;
        uint direction;

        void init_pin();

};

void cl_gpio::init_pin()
{
    gpio_init()
}

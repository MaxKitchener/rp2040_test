#include <stdio.h>

#include "pico/stdlib.h"

typedef struct ts_gpio_config
{
    uint pin;
    uint direction;
}ts_gpio_config;

const ts_gpio_config gpio[] =
{
  { PICO_DEFAULT_LED_PIN,    GPIO_OUT},
  { 15,         GPIO_OUT},
  { 0,           0}
};


void init_gpio(void)
{
    uint index = 0;
    while (gpio[index].pin != 0)
    {
        gpio_init(gpio[index].pin);
        gpio_set_dir(gpio[index].pin, gpio[index].direction);
        index++;
    }
}

int main()
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    init_gpio();

    while (true)
    {
        gpio_put(LED_PIN, 1);
        gpio_put(15, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        gpio_put(15, 1);
        sleep_ms(250);
    }
}

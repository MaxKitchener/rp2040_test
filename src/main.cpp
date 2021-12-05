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

#include "gpio.h"
#include "i2c.h"
#include "vt100.h"

#define BOOT_DELAY 1500

const char* rasbpi_logo =
"\x1b[32m '~*iT}v=     !?LT}r>.\n"
"  m@@#B@@@@] r@@@@B#@@d\n"
"  :#@@@QDZBG kBZEQ@@@#=\n"
"   'uB@@@$`   `N@@@By.``\n"
"\x1b[31m     _]k*.xIPUi_!V], `''`\n"
"   `m8M* ^q$8gOL *G8G`\n"
"   _v,*tMMV_ -kNEGi!v!\n"
" 'VI I88888Z k88888N`PX-\n"
" U8Z d8888$r '98888E`d83\n"
" *$> `r}}viVIwx*?v^`'^R^\n"
"   tdU*  d88888$'.TD8P\n"
"   K888Z`y88888H:0888H\n"
"    ?G$D! -*x?_ )ggMx`\n"
"         }E888gU\n"
"          :)x/!\x1b[37m\n";

/**
 * @brief
 *
 * @return int
 */
int main()
{
    uint counter = 0;
    stdio_init_all(); // initialise uart
    cl_i2c i2c(i2c_default, PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, 25000);
    tc_vt100 terminal;

    gpio[0].init();
    gpio[1].init();
    gpio[2].init();

    i2c.init();

    while(!gpio[2].read())
    {
        gpio[0].write(1);
    }

    sleep_ms(BOOT_DELAY);
    terminal.set_cursor(0, 0);
    terminal.clear_screen();
    terminal.clear_terminal();

    printf(rasbpi_logo);

    i2c.scan(true);

    printf("Hello World!\n");

    while (true)
    {
        gpio[0].write(1);
        gpio[1].write(0);
        sleep_ms(250);
        gpio[0].write(0);
        gpio[1].write(1);
        sleep_ms(250);
        counter++;

        if(counter == 10)
        {
            counter = 0;
            printf("\x1b[31mIs thing on\x1b[0m?\n");
            //printf("Is thing on?");
        }

    }
}

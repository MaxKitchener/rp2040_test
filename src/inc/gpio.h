/*
 * ****************************************************************************
 * File           :       gpio.h
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */

#ifndef _GPIO_H
#define _GPIO_H

#include "global.h"

#define NUM_GPIO 2

class tc_pin
{
    private:
        uint pin_no;
        uint direction;
        uint pullup;

    public:
        tc_pin(uint _pin_no, uint _direction, uint _pullup);
        void init();
        uint read();
        void write(uint value);
        uint get_pin_no();
        uint get_direction();
};


extern tc_pin gpio[];

#endif

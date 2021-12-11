/*
 * ****************************************************************************
 * File           :       vt100.cpp
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */
#include "stdio.h"
#include "stdarg.h"

#include "vt100.h"

// PRIVATE
uint tc_vt100::boundary_check(uint value, uint lower, uint upper)
{
    uint retval = 0;
    if(!((lower > upper)||(upper < lower)))
    {
        retval = value;
        if(retval < lower) retval = lower;
        if(retval > upper) retval = upper;
    }
    return(retval);
}

// PUBLIC
tc_vt100::tc_vt100()
{
    cursor_row = 0;
    cursor_collumn = 0;
}

void tc_vt100::print(const char* string, ...)
{
    va_list valist;

    va_start(valist, string);

    printf(string, valist);

    va_end(valist);
}


void tc_vt100::set_colour(te_ansi_colour colour)
{
    printf("\x1b[3%1im", colour);
}

void tc_vt100::clear_screen()
{
    printf("\x1b[2J");
}

void tc_vt100::clear_terminal()
{
    printf("\x1b[3J");
}

void tc_vt100::set_cursor(uint collumn, uint row)
{
    cursor_row     = boundary_check(row,    1, window_height-1);
    cursor_collumn = boundary_check(collumn, 1, window_width-1);

    printf("\x1b[%i;%iH", cursor_row, cursor_collumn);
}


void tc_vt100::set_window_size(uint width, uint height)
{
    window_width = width;
    window_height = height;
}

void tc_vt100::print_window_border()
{
    set_cursor(1,1);
    for (uint i = 0; i < window_width; i++)
    {
        printf("-");
    }
    set_cursor(1,2);
    for (uint row = 0; row < window_height-2; row++)
    {
        printf("|%*s|\n", window_width-2, "");
    }
    for (uint i = 0; i < window_width; i++)
    {
        printf("-");
    }
}

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

tc_vt100::tc_vt100()
{
    cursor_row = 0;
    cursor_collumn = 0;
}

void tc_vt100::print(char* string, ...)
{
    va_list valist;

    va_start(valist, string);

    printf(string, valist);

    va_end(valist);
}

void tc_vt100::clear_screen()
{
    printf("\x1b[2J");
}

void tc_vt100::clear_terminal()
{
    printf("\x1b[3J");
}

void tc_vt100::set_cursor(uint row, uint collumn)
{
    cursor_collumn = collumn;
    cursor_row = row;

    printf("\x1b[%i;%iH", cursor_row, cursor_collumn);
}

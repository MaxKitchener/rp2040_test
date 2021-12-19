/*
 * ****************************************************************************
 * File           :       _table.cpp
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */

#include "tui.h"
#include "tui/table.h"

tc_table::tc_table(tc_vt100* terminal, const char* title, ts_table_entry* table, uint width, uint height)
{
    uint table_len = 0;

    _term = terminal;
    _title = title;
    _table = table;
    _table_width = width;

    if(_table != NULL)
    {
        while(table_len < 20)
        {
            if(_table[table_len].string == NULL || _table[table_len].string == 0)
            {
                break;
            }
            else
            {
                table_len++;
            }
        }
    }

    _table_entries = table_len;

    _table_height = 2; //window title box
    _table_height += table_len;

    if(_table_height < height)
    {
        _table_height = height;
    }
}

void tc_table::print_table_at_pos(uint x, uint y)
{
    _term->set_cursor(x, y);
    _term->create_window_at_pos(_table_width, _table_height, _title, x, y);

    x+=1;
    y+=3;

    for (uint row = 0; row < _table_entries; row++)
    {
        uint val = 0;
        _term->set_cursor(x, y+row);
        printf("%-*.*s", _table_width-10, _table_width-10, _table[row].string);
        _term->set_cursor(x+(_table_width-8), y+row);
        switch(_table[row].type)
        {
            case UINT8:
                val = *(uint8_t *)_table[row].value;
                printf("%6i", val);
                break;
            case UINT16:
                printf("%6i", *(uint16_t *)_table[row].value);
                break;
            case HEX8:
                printf("  0x%02X", *(uint8_t *)_table[row].value);
                break;
            case FLOAT:
                printf("%6.2f", *(float *)_table[row].value);
                break;
        }
    }

}

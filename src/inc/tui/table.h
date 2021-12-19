#ifndef _TABLE_H
#define _TABLE_H

#include "tui.h"

typedef enum te_type
{
    STRING,
    UINT8,
    UINT16,
    UINT32,
    HEX8,
    HEX16,
    HEX32,
    ARRAY,
    FLOAT,
    EOT
}te_type;

typedef struct ts_table_entry
{
    const char* string;
    void* value;
    te_type type;
}ts_table_entry;

class tc_table
{
    private:
        const char* _title;
        tc_vt100* _term;
        ts_table_entry* _table;
        uint _table_width;
        uint _table_height;
        uint _table_entries;
    public:
        tc_table(tc_vt100* terminal, const char* title, ts_table_entry* table, uint width, uint height);
        void print_table_at_pos(uint x, uint y);
};


#endif

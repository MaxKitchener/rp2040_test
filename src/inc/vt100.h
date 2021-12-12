/*
 * ****************************************************************************
 * File           :       vt100.h
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */


#ifndef _VT100_H
#define _VT100_H

#include "global.h"

// SGR(Select Graphic Rendition)
#define ANSI_SGR_RESET 0x00;
#define ANSI_SGR_BOLD 0x01;
#define ANSI_SGR_DIM 0x02;
#define ANSI_SGR_ITALIC 0x03;
#define ANSI_SGR_UNDERLINE 0x04;
#define ANSI_SGR_BLINK 0x05;
//#define ANSI_SGR_BLINK_FAST 0x06;
#define ANSI_SGR_INVERT 0x07;
//#define ANSI_SGR_HIDE 0x08;
#define ANSI_SGR_STRIKE 0x09;
#define ANSI_SGR_FONT_0 0x10;
#define ANSI_SGR_FONT_1 0x11;
#define ANSI_SGR_FONT_2 0x12;
#define ANSI_SGR_FONT_3 0x13;
#define ANSI_SGR_FONT_4 0x14;
#define ANSI_SGR_FONT_5 0x15;
#define ANSI_SGR_FONT_6 0x16;
#define ANSI_SGR_FONT_7 0x17;
#define ANSI_SGR_FONT_8 0x18;
#define ANSI_SGR_FONT_9 0x19;
#define ANSI_SGR_FRAKTUR 0x20;
//#define ANSI_SGR_UNDERLINE_DOUBEL 0x21;
//#define ANSI_SGR_NORMAL_INTENSITY 0x22;
#define ANSI_SGR_NOT_ITALIC_NOT_BLACK 0x23;
#define ANSI_SGR_NOT_UNDERLINED 0x24;
#define ANSI_SGR_NOT_BLINKING 0x25;
//#define ANSI_SGR_PROPORTIONAL 0x26;
#define ANSI_SGR_NOT_REVERSED 0x27;
#define ANSI_SGR_NOT_CONCEALED 0x28;
#define ANSI_SGR_NOT_STRIKED 0x29;
#define ANSI_SGR_SET_COLOUR_FORE_8 0x30;
#define ANSI_SGR_SET_COLOUR_BACK 0x40;
//#define ANSI_SGR_NOT_PROPORIONAL 0x50;

enum te_ansi_colour
{
    BLACK   = 0x00,
    RED     = 0x01,
    GREEN   = 0x02,
    YELLOW  = 0x03,
    BLUE    = 0x04,
    MAGENTA = 0x05,
    CYAN    = 0x06,
    WHITE   = 0x07,
    EXTENDED= 0x08,
    DEFAULT = 0x09
};

class tc_vt100
{
    private:
        uint cursor_row;
        uint cursor_collumn;
        uint window_width;
        uint window_height;

        uint boundary_check(uint value, uint lower, uint upper);

    public:

        tc_vt100();
        void print(const char* string, ...);
        void set_colour(te_ansi_colour colour);
        //void set_colour_extended(uint r, uint g, uint b);
        //void set_bold(uint enable);
        //void set_italic(uint enable);
        //void set_underlined(uint enable);
        void set_cursor(uint row, uint collumn);
        //uint get_cursor_row();
        //uint get_cursor_collumn();
        void clear_screen();
        void clear_terminal();

        void set_window_size(uint width, uint height);
        void create_window_at_pos(uint width, uint height, const char* title, uint x, uint y);

};

#endif

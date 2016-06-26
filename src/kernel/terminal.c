#include "kernel/terminal.h"

#define VGA_BLACK        (0x00)
#define VGA_BLUE         (0x01)
#define VGA_GREEN        (0x02)
#define VGA_DARK_CYAN    (0x03)
#define VGA_RED          (0x04)
#define VGA_PURPLE       (0x05)
#define VGA_BROWN        (0x06)
#define VGA_DARK_GRAY    (0x07)
#define VGA_LIGHT_GRAY   (0x08)
#define VGA_LIGHT_BLUE   (0x09)
#define VGA_LIGHT_GREEN  (0x0A)
#define VGA_CYAN         (0x0B)
#define VGA_PINK         (0x0C)
#define VGA_LIGHT_PURPLE (0x0D)
#define VGA_YELLOW       (0x0E)
#define VGA_WHITE        (0x0F)

#define VGA_WIDTH  (80)
#define VGA_HEIGHT (25)

#define VGA_MAKE_COLOR(fg, bg) \
    (((bg) << 4) | (fg))

#define VGA_MAKE_ENTRY(c, color) \
    ((c) | ((color) << 8))


static void term_shift_up();
static void term_next_line();


static uint16_t* term = (uint16_t*)0xB8000;
static size_t term_pos = 0;
static size_t term_size = VGA_HEIGHT * VGA_WIDTH;
static uint8_t term_color = VGA_MAKE_COLOR(VGA_BLUE, VGA_WHITE);


void term_init()
{
    for (size_t i = 0; i < term_size; i++) {
        term[i] = VGA_MAKE_ENTRY(' ', term_color);
    }
}



void term_write_byte(char byte)
{
    if (byte < 0x20 && byte != '\n')
        return;

    if (byte != '\n') {
        // Writing byte in current position
        term[term_pos] = VGA_MAKE_ENTRY(byte, term_color);

        // Computing the next carrige position
        if (term_pos < term_size - 1) {
            term_pos++;
        }
        else {
            term_next_line();
        }
    }
    else {
        term_next_line();
    }
}



void term_put_string(char* s)
{
    for (size_t i = 0; s[i] != 0; i++) {
        term_write_byte(s[i]);
    }
}



void term_printf(char* format, ...)
{
    int* args = ((int*)(&format));
    size_t curr_arg = 1;

    for (int i = 0; format[i] != '\0'; i++) {
        char c = format[i];

        if (c == '%') {
            if (format[i + 1] == '\0') {
                break;
            }

            char buf[12];
            if (format[i + 1] == 'd') {
                size_t ret = itoa_i(args[curr_arg], buf, sizeof(buf));
                if (ret == ERROR_SUCCESS) {
                    term_put_string(buf);
                }
                else {
                    term_put_string("?");
                }
                curr_arg++;
            }
            else if (format[i + 1] == 'u') {
                size_t ret = itoa_u(args[curr_arg], buf, sizeof(buf));
                if (ret == ERROR_SUCCESS) {
                    term_put_string(buf);
                }
                else {
                    term_put_string("?");
                }
                curr_arg++;
            }
            else if (format[i + 1] == 'x') {
                size_t ret = itoa_x32(args[curr_arg], buf, sizeof(buf));
                if (ret == ERROR_SUCCESS) {
                    term_put_string(buf);
                }
                else {
                    term_put_string("?");
                }
                curr_arg++;
            }
            else if (format[i + 1] == 's') {
                term_put_string(args[curr_arg]);
                curr_arg++;
            }

            i++;
        }
        else {
            term_write_byte(c);
        }
    }
}



static void term_shift_up()
{
    for (size_t i = 0; i < term_size - VGA_WIDTH; i++) {
        term[i] = term[i + VGA_WIDTH];
    }

    for (size_t i = term_size - VGA_WIDTH; i < term_size; i++) {
        term[i] = VGA_MAKE_ENTRY(' ', term_color);
    }
}



static void term_next_line()
{
    if (term_pos < term_size - VGA_WIDTH) {
        term_pos += VGA_WIDTH - (term_pos % VGA_WIDTH);
    }
    else {
        term_shift_up();
        term_pos = term_size - VGA_WIDTH;
    }
}

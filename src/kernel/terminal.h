#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <stdint.h>
#include <stddef.h>
#include <utils/string.h>

void term_printf(char* format, ...);
void term_put_string(char* s);
void term_write_byte(char byte);
void term_init();

#endif

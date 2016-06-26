#include "kernel/fiasco.h"
#include "kernel/terminal.h"


void _end();

void fiasco(char* msg)
{
    term_put_string(msg);
    term_put_string("\n ------ pizdec ------ ");
    _end();
}

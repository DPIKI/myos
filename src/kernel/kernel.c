#include "kernel/terminal.h"

uint8_t* memmgr_init(uint8_t kernel_end, size_t bytes_available); 

void fiasco();

void kmain(uint32_t magic)
{
    term_init();
    term_printf("test number %i %u %x", 0x80000000, 0x80000000, 0x80000000);
}


void _end();

void fiasco()
{
    term_put_string(" ------ pizdec ------ ");
    _end();
}

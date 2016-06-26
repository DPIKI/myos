#include "kernel/terminal.h"
#include "kernel/fiasco.h"
#include "kernel/memmgr.h"

void fiasco();

void kmain(
    uint32_t flags,
    uint32_t mem_lower,
    uint32_t mem_upper,
    uint32_t mmap_length,
    uint8_t* mmap_addr)
{
    term_init();
    term_printf("flags: %x\n", flags);
    term_printf("mem_lower: %x\n", mem_lower);
    term_printf("mem_upper: %x\n", mem_upper);
    term_printf("mmap_addr: %x\n", mmap_addr);
    term_printf("mmap_length: %d\n", mmap_length);

    for (size_t i = 0; i < mmap_length; i += (*(uint32_t*)(mmap_addr + i) + 4)) {
        uint32_t size = *(uint32_t*)(mmap_addr + i);
        uint64_t base_addr = *(uint64_t*)(mmap_addr + i + 4);
        uint64_t length = *(uint64_t*)(mmap_addr + i + 12);
        term_printf("size: %d\n", size);
        term_printf("base_addr: %x %x\n", (uint32_t*)(&base_addr)[1], (uint32_t*)(&base_addr)[0]);
        term_printf("length: %x %x\n", (uint32_t*)(&length)[1], (uint32_t*)(&length)[0]);
    }
}

ENTRY(_start)

SECTIONS 
{
    . = 0x10000;
    .text BLOCK(4K) : ALIGN(4K) {
        *(.multiboot) 
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K) {
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K) {
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K) {
        *(COMMON)
        *(.bss)
        *(.boot_stack)
    }
    kernel_end = . ;
}

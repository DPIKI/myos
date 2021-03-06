.set ALIGN, 1<<0
.set MEMINFO, 1<<1
.set MAGIC, 0x1BADB002
.set FLAGS, ALIGN | MEMINFO
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .boot_stack
stack_bottom:
.skip 0xFFFF
stack_top:

.section .text
.global _start
.global _end
.type start, @function

_start:
    movl $stack_top, %esp
    pushl 48(%ebx)
    pushl 44(%ebx)
    pushl 8(%ebx)
    pushl 4(%ebx)
    pushl 0(%ebx)
    call kmain

_end:
    jmp _end

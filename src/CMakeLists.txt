cmake_minimum_required(VERSION 3.0.2)

SET(CMAKE_TOOLCHAIN_FILE ~/src/toolchain-i686-elf.cmake)

project(myos.bin)

# Configuring asm compiler
enable_language(ASM)

# Configuring c compiler
SET(CMAKE_C_FLAGS "-O2 -Wall -Wextra -ffreestanding -std=gnu99")

# Configuring the linker
SET(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld")
SET(CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT} -ffreestanding -O2 -nostdlib -lgcc")

# Configufing include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Compiling the kernel
SET(SOURCES ${SOURCES} kernel/kernel.c)
SET(SOURCES ${SOURCES} kernel/terminal.c)
SET(SOURCES ${SOURCES} kernel/boot.S)
SET(SOURCES ${SOURCES} utils/string.c)
add_executable(myos.bin ${SOURCES})

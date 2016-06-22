cmake_minimum_required(VERSION 3.0.2)

project(myos)

# Compiling kernel
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_custom_target(kernel DEPENDS myos.bin)

# Generating bootable image
add_custom_command(OUTPUT myos.iso
    COMMAND mkdir -p isodir/boot/grub
    COMMAND cp src/myos.bin isodir/boot/myos.bin
    COMMAND cp ${CMAKE_SOURCE_DIR}/grub.cfg isodir/boot/grub/grub.cfg
    COMMAND grub-mkrescue -o myos.iso isodir
    DEPENDS src/myos.bin ${CMAKE_SOURCE_DIR}/grub.cfg
    COMMENT " -- Creating bootable image --")
add_custom_target(bootable
    DEPENDS myos.iso)

# Generate documentation
SET(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR}/src)
SET(DOXYGEN_OUTPUT ${CMAKE_SOURCE_DIR}/doc)
CONFIGURE_FILE(
    ${CMAKE_SOURCE_DIR}/doc.conf.in 
    ${CMAKE_CURRENT_BINARY_DIR}/doxy.conf)
add_custom_target(documentation
    COMMAND doxygen doxy.conf)

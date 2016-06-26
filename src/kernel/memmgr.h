#ifndef _MEMMGR_H_
#define _MEMMGR_H_

#include "utils/bitmap.h"

#define MEM_PAGE_SIZE           (0x00001000)

#define MEM_PDE_PRESENT         (0x00000001)
#define MEM_PDE_RW              (0x00000002)
#define MEM_PDE_USER_PRIV       (0x00000004)
#define MEM_PDE_WRITE_THROW     (0x00000008)
#define MEM_PDE_CACHE_DISABLE   (0x00000010)
#define MEM_PDE_ACCESSED        (0x00000020)
#define MEM_PDE_PAGE_SIZE       (0x00000080)

#define MEM_PTE_PRESENT         (0x00000001)
#define MEM_PTE_RW              (0x00000002)
#define MEM_PTE_USER_PRIV       (0x00000004)
#define MEM_PTE_WRITE_THROW     (0x00000008)
#define MEM_PTE_CACHE_DISABLE   (0x00000010)
#define MEM_PTE_ACCESSED        (0x00000020)
#define MEM_PTE_DIRTY           (0x00000040)
#define MEM_PTE_GLOBAL          (0x00000080)

#define MEM_MAKE_PAGE_ENTRY(page_index, flags) (((page_index) << 12) | (flags))

/**
 * \brief Defines address space of the process.
 */
typedef struct {
    uint32_t* page_dir_phys;                        ///< Physical address of the page directory.
    uint32_t* page_dir_log;                         ///< Logical address of the page directory.
    uint32_t* page_tables_log[MEM_PAGE_SIZE >> 2];  ///< Array of logical addresses of page tables.
} AddressSpace;


/**
 * \brief Kernel AddressSpace.
 */
AddressSpace k_addrsp;


/**
 * \brief Initializes memory manager data structures
 * and returns AddressSpace struct of the kernel.
 *
 * \param as [out]          AddressSpace struct that will be initialized.
 * \param mem_low_limit     Memory limit under 1MB. This value provided by the multiboot bootloader.
 * \param mem_high_limit    Memory limit above 1MB. This value provided by the multiboot bootloader.
 */
void mem_init(size_t mem_low_limit, size_t mem_high_limit);

#endif

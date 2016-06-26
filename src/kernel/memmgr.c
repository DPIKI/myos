#include "kernel/memmgr.h"
#include "kernel/terminal.h"
#include "utils/mem.h"


extern uint8_t* kernel_end;
AddressSpace k_addrsp = { 0 };
Bitmap phys_mem_bitmap;

void mem_init(size_t mem_low_limit, size_t mem_high_limit)
{
    // Initializing physical memory bitmap.
    bitmap_init(&phys_mem_bitmap, kernel_end, (mem_high_limit + 0x00100000) >> 12);

    // Finding index of first free page.
    size_t page_dir_index = ((size_t)(kernel_end + phys_mem_bitmap.n_bytes) >> 12) + 1;

    // Remembering physical and logical addresses of page directory.
    k_addrsp.page_dir_phys = page_dir_index << 12;
    k_addrsp.page_dir_log  = page_dir_index << 12;

    // Marking page directory's page in phys mem bitmap
    bitmap_set_bit(&phys_mem_bitmap, page_dir_index);

    // Clearing page directory and array of logical addresses of page tables.
    memset(k_addrsp.page_dir_log, MEM_PAGE_SIZE, 0);
    memset(k_addrsp.page_tables_log, sizeof(k_addrsp.page_tables_log), 0);

    for (uint8_t* i = 0x00100000; i < kernel_end; i += MEM_PAGE_SIZE) {
        size_t pd_i = (uint32_t)i >> 22;
        size_t pt_i = ((uint32_t)i >> 12) & 0x3FF;
        
        // If needed page table does not exist.
        if (k_addrsp.page_dir_log[pd_i] == 0) {

            // Searching for not allocated page.
            int free_page = bitmap_find_null(&phys_mem_bitmap, page_dir_index);
            if (free_page == -1) {
                // TODO: If failed then abort.
            }

            // Marking allocated page in bitmap.
            bitmap_set_bit(&phys_mem_bitmap, free_page);

            // Filling entry in page directory.
            k_addrsp.page_dir_log[pd_i] = MEM_MAKE_PAGE_ENTRY(free_page,
                    MEM_PDE_PRESENT |
                    MEM_PDE_RW);
            
            // Remembering its logical address (which is equal to phys addr in this case).
            k_addrsp.page_tables_log[pd_i] = free_page << 12;

            // Filling new page table with zeros.
            memset(k_addrsp.page_tables_log[pd_i], MEM_PAGE_SIZE, 0);
        }

        // Searching for not allocated page.
        int free_page = bitmap_find_null(&phys_mem_bitmap, page_dir_index);
        if (free_page == -1) {
            // TODO: If failed then abort.
        }

        // Marking allocated page in bitmap.
        bitmap_set_bit(&phys_mem_bitmap, free_page);

        // Filling entry in page directory.
        k_addrsp.page_tables_log[pt_i] = MEM_MAKE_PAGE_ENTRY((uint32_t)free_page,
                MEM_PTE_GLOBAL |
                MEM_PTE_RW |
                MEM_PTE_PRESENT);
        
        // Remembering its logical address (which is equal to phys addr in this case).
        k_addrsp.page_tables_log[pt_i] = (uint32_t)free_page << 12;
    }
}





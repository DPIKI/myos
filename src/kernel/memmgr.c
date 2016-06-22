#include "kernel/memmgr.h"


extern uint8_t kernel_end;
AddressSpace k_addrsp;
Bitmap phys_mem_bitmap;

error_t mem_init(AddressSpace* as, size_t mem_low_limit, size_t mem_high_limit)
{
    bitmap_init(&phys_mem_bitmap, kernel_end, (mem_high_limit + 0x00100000) >> 12);

    size_t page_dir_index = ((kernel_end + phys_mem_bitmap->n_bytes) >> 12) + 1;
    k_addrsp->page_dir_phys = page_dir_index << 12;
    k_addrsp->page_dir_log  = page_dir_index << 12;
    bitmap_set_bit(&phys_mem_bitmap, page_dir_index);

    for (size_t i = 0; i < MEM_PAGE_SIZE; i++) {
        k_addrsp->page_dir_log[i] = 0;
    }

    uint8_t* i = 0x00100000;
    while (i < kernel_end) {
        size_t pd_i = i >> 22;
        size_t pt_i = (i >> 12) & 0x3FF;
        
        if (pt_i == 0) {
            int free_page = bitmap_find_one(&phys_mem_bitmap, page_dir_index);
            if (free_page == -1) {

            }

            k_addrsp->page_dir_log = 
        }
    }
}

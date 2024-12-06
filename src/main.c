#include <stdio.h>
#include "mmu.h"

int main() {
    MMU mmu;
    initialize_mmu(&mmu, 1024 * 1024, 4096 * 4096);

    printf("Simulating Memory Management Unit:\n");

    int virtual_addresses[] = {0x1234, 0x5678, 0x9ABC, 0x1234};
    const char *policy = "FIFO";

    for (int i = 0; i < 4; i++) {
        int physical_address = translate_address(&mmu, virtual_addresses[i], policy);
        printf("Virtual Address: 0x%X -> Physical Address: 0x%X\n", virtual_addresses[i], physical_address);
    }

    print_statistics(&mmu);

    cleanup_mmu(&mmu);
    return 0;
}
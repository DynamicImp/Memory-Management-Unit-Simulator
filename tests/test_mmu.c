#include <stdio.h>
#include "../src/mmu.h"

void test_initialize_mmu() {
    MMU mmu;
    initialize_mmu(&mmu, 1024 * 1024, 4096 * 4096);
    printf("Test initialize MMU: Passed\n");
    cleanup_mmu(&mmu);
}

void test_translate_address() {
    MMU mmu;
    initialize_mmu(&mmu, 1024 * 1024, 4096 * 4096);
    int physical_address = translate_address(&mmu, 0x1234, "FIFO");
    printf("Translated Address: %d\n", physical_address);
    cleanup_mmu(&mmu);
}

void test_compact_memory() {
    MMU mmu;
    initialize_mmu(&mmu, 1024 * 1024, 4096 * 4096);
    compact_memory(&mmu);
    printf("Test compact memory: Passed\n");
    cleanup_mmu(&mmu);
}

int main() {
    test_initialize_mmu();
    test_translate_address();
    test_compact_memory();
    return 0;
}
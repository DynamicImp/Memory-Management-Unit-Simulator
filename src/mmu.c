#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mmu.h"

#define PAGE_SIZE 4096
#define TLB_SIZE 16

void initialize_mmu(MMU *mmu, int memory_size, int virtual_memory_size) {
    mmu->memory_size = memory_size;
    mmu->virtual_memory_size = virtual_memory_size;
    mmu->page_table = malloc(virtual_memory_size / PAGE_SIZE * sizeof(int));
    mmu->tlb = malloc(TLB_SIZE * sizeof(TLBEntry));
    mmu->page_faults = 0;
    mmu->clock_pointer = 0;
    memset(mmu->page_table, -1, virtual_memory_size / PAGE_SIZE * sizeof(int));
    for (int i = 0; i < TLB_SIZE; i++) {
        mmu->tlb[i].page_number = -1;
        mmu->tlb[i].frame_number = -1;
        mmu->tlb[i].access_time = 0;
    }
}

int translate_address(MMU *mmu, int virtual_address, const char *policy) {
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;

    // Check TLB
    for (int i = 0; i < TLB_SIZE; i++) {
        if (mmu->tlb[i].page_number == page_number) {
            return mmu->tlb[i].frame_number * PAGE_SIZE + offset;
        }
    }

    // Check page table
    if (mmu->page_table[page_number] == -1) {
        handle_page_fault(mmu, page_number, policy);
    }

    // Update TLB
    update_tlb(mmu, page_number, mmu->page_table[page_number]);

    return mmu->page_table[page_number] * PAGE_SIZE + offset;
}

void handle_page_fault(MMU *mmu, int page_number, const char *policy) {
    mmu->page_faults++;
    // Simulate loading the page into memory (simplified)
    int frame_number = page_number % (mmu->memory_size / PAGE_SIZE);
    mmu->page_table[page_number] = frame_number;

    // Apply page replacement policy if necessary
    apply_page_replacement(mmu, policy);
}

void update_tlb(MMU *mmu, int page_number, int frame_number) {
    static int tlb_index = 0;
    mmu->tlb[tlb_index].page_number = page_number;
    mmu->tlb[tlb_index].frame_number = frame_number;
    mmu->tlb[tlb_index].access_time = clock();
    tlb_index = (tlb_index + 1) % TLB_SIZE;
}

void apply_page_replacement(MMU *mmu, const char *policy) {
    if (strcmp(policy, "LRU") == 0) {
        // Implement LRU replacement logic
    } else if (strcmp(policy, "Clock") == 0) {
        // Implement Clock replacement logic
    } else if (strcmp(policy, "FIFO") == 0) {
        // Implement FIFO replacement logic
    }
}

void compact_memory(MMU *mmu) {
    // Memory compaction logic
}

void print_statistics(MMU *mmu) {
    printf("Page Faults: %d\n", mmu->page_faults);
}

void cleanup_mmu(MMU *mmu) {
    free(mmu->page_table);
    free(mmu->tlb);
}
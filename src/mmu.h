#ifndef MMU_H
#define MMU_H

typedef struct {
    int page_number;
    int frame_number;
    int access_time;
} TLBEntry;

typedef struct {
    int *page_table;
    TLBEntry *tlb;
    int memory_size;
    int virtual_memory_size;
    int page_faults;
    int clock_pointer;
} MMU;

void initialize_mmu(MMU *mmu, int memory_size, int virtual_memory_size);
int translate_address(MMU *mmu, int virtual_address, const char *policy);
void handle_page_fault(MMU *mmu, int page_number, const char *policy);
void update_tlb(MMU *mmu, int page_number, int frame_number);
void apply_page_replacement(MMU *mmu, const char *policy);
void compact_memory(MMU *mmu);
void print_statistics(MMU *mmu);
void cleanup_mmu(MMU *mmu);

#endif // MMU_H
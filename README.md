# Memory Management Unit Simulator

## Overview
This project simulates a Memory Management Unit (MMU), implementing key features like multi-level paging, TLB, page replacement algorithms, and memory compaction.

## Features
- Simulate physical and virtual address spaces
- Handle page faults
- Track page table entries
- Visualize memory allocation
- Provide page fault statistics

## Build Instructions
```bash
make
```

## Usage Examples
Run the main program:
```bash
./mmu
```
Run the tests:
```bash
./test
```

## Design Decisions
- Used `C` for close-to-hardware simulation.
- Multiple replacement algorithms for learning comparison.

## Known Limitations
- Simulation-specific simplifications in address translation.

## References
- Tanenbaum, A. S., & Bos, H. (2015). Modern Operating Systems.
```

#### slides/presentation.pptx
**Placeholder:** Create slides on Virtual Memory Concepts, Address Translation, Page Replacement Policies, and Project Workflow.

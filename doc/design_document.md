# Design Document

## System Overview
The Memory Management Unit Simulator is designed to mimic the behavior of a real-world memory management unit. It handles memory allocation, deallocation, and tracking, providing insights into system performance and usage.

## Architecture
### Core Components
- **Memory Pool:** A contiguous block of memory that simulates physical RAM.
- **Allocation Table:** Tracks allocated and free memory blocks.

### Modules
1. **Initialization:** Sets up the memory pool.
2. **Allocation/Deallocation:** Handles requests for memory blocks.
3. **Statistics:** Tracks usage metrics.

## Data Flow
1. **Initialization:**
   - Memory pool and allocation table are initialized.
2. **Allocation:**
   - Request is checked against available space.
   - Memory block is reserved, and the table is updated.
3. **Deallocation:**
   - Block is marked free in the table.
   - Adjacent free blocks are merged.

## Key Algorithms
1. **First-Fit Allocation:** Searches for the first free block that fits the requested size.
2. **Coalescing:** Combines adjacent free blocks to minimize fragmentation.

## Trade-offs
- **Advantages:** Efficient allocation and deallocation.
- **Disadvantages:** Susceptible to fragmentation.

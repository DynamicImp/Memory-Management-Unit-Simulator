# API Documentation

## Initialization Functions
- **`void init_memory(unsigned int size)`**: Initializes the memory with the specified size.
  - **Parameters:** `size` - Size of memory to initialize.
  - **Returns:** None.

- **`void reset_memory()`**: Resets the memory to its initial state.
  - **Parameters:** None.
  - **Returns:** None.

## Allocation Functions
- **`void* allocate_memory(unsigned int size)`**: Allocates a block of memory.
  - **Parameters:** `size` - Size of the memory block to allocate.
  - **Returns:** Pointer to the allocated memory block.

- **`void free_memory(void* ptr)`**: Frees the specified memory block.
  - **Parameters:** `ptr` - Pointer to the memory block to free.
  - **Returns:** None.

## Utility Functions
- **`unsigned int get_memory_usage()`**: Retrieves the current memory usage.
  - **Parameters:** None.
  - **Returns:** Memory usage in bytes.

- **`unsigned int get_free_space()`**: Retrieves the remaining free memory.
  - **Parameters:** None.
  - **Returns:** Free memory in bytes.

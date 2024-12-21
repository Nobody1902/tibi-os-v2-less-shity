#include "heap.h"
#include "string.h"

extern char __heap_start__; // Defined in linker script
extern char __heap_end__;   // Defined in linker script

static char* current_break = NULL; // Pointer to the current end of allocated memory

typedef struct Block {
    size_t size;          // Size of the block (excluding the header)
    struct Block* next;   // Pointer to the next free block
} Block;

static Block* free_list = NULL;  // Head of the free list

void* sbrk(intptr_t increment) {
  if (!current_break) {
    current_break = &__heap_start__; // Initialize on first call
  }

  if (increment < 0) {
    // Handle deallocation (not implemented in this simple version)
    return (void *)-1; // Returning -1 for simplicity
  }

  if (current_break + increment > &__heap_end__) {
    return (void *)-1; // Out of memory
  }

  char *prev_break = current_break; // Store the previous break
  current_break += increment;         // Move the break
  return prev_break;                  // Return the old break address
}

void* malloc(size_t size) {
  if (size == 0) return NULL;

  // Align size to be a multiple of sizeof(size_t)
  size_t total_size = size + sizeof(Block); // Include space for metadata

  // Search for a suitable block in the free list
  Block* current = free_list;
  Block* prev = NULL;

  while (current != NULL) {
    if (current->size >= size) {
      if (prev != NULL) {
        prev->next = current->next;  // Remove from free list
      } else {
        free_list = current->next;  // Update head of free list
      }
      return (void*)(current + 1);  // Return pointer to usable memory
    }
    prev = current;
    current = current->next;
  }

  // No suitable block found, expand the heap if possible
  char* block = sbrk(total_size);
  if (block == (void*)-1) {
    return NULL; // Out of memory
  }

  Block* new_block = (Block*)block;
  new_block->size = size;           // Set block size
  new_block->next = NULL;           // No next block yet

  return (void*)(new_block + 1);   // Return pointer to usable memory
}

void free(void* ptr) {
  if (!ptr) return;

  Block* block = (Block*)ptr - 1;  // Get the block header

  // Add the block back to the free list
  block->next = free_list;           // Link to previous head of free list
  free_list = block;                  // Update head of free list
}

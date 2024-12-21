#include "def.h"

#ifndef HEAP_H
#define HEAP_H

// Defined by linker
extern char __heap_start__;
extern char __heap_end__;

void* sbrk(intptr_t ptr);
void* malloc(size_t size);
void free(void* ptr);

#endif

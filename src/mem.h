#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"

#include "def.h"

#ifndef MEM_H
#define MEM_H

void* memset(void* b, int c, int len);
void memcpy(void* dest, void* src, int size);;
// TODO: Implement malloc and free
/*void* malloc(size_t size);*/
/*void free(void* ptr);*/

#endif

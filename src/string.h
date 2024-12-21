#include "def.h"

#ifndef STRING_H
#define STRING_H

#define NULL ( (void *) 0)

int strcmp(const char* s1, const char* s2);
size_t strlen(const char* str);
u64 hex2u64(char* str);
void itos(i64 value, char* buffer);
void ftos(float value, char *buffer);

#endif

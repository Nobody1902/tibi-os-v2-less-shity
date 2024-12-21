#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"

#include "mem.h"
#include "def.h"

void* memset(void* b, int c, int len) {
  int i;
  unsigned char* p = b;
  i = 0;
  while(len > 0) {
    *p = c;
    p++;
    len--;
  }
  return b;
}

void memcpy(void* dest, void* src, int size) {
  uint8_t *pdest = (uint8_t*) dest;
  uint8_t *psrc = (uint8_t*) src;

  int loops = (size / sizeof(uint32_t));
  for(int index = 0; index < loops; ++index) {
      *((uint32_t*)pdest) = *((uint32_t*)psrc);
      pdest += sizeof(uint32_t);
      psrc += sizeof(uint32_t);
  }

  loops = (size % sizeof(uint32_t));
  for (int index = 0; index < loops; ++index) {
      *pdest = *psrc;
      ++pdest;
      ++psrc;
  }
}

// TODO: Implement malloc and free
/*void* malloc(size_t size) {*/
/*  return 0;*/
/*}*/
/**/
/*void free(void* ptr) {*/
/**/
/*}*/

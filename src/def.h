#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"

#include <stdint.h>

#ifndef DEF_H
#define DEF_H

typedef int bool;
#define true  1
#define false 0

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef i64 intptr_t;
typedef u64 uintptr_t;

typedef u64 size_t;

#endif

#ifndef __API__
#define __API__

#include <stdint.h>

uint32_t createPartition(uint32_t root, uint32_t pd, uint32_t sh1, uint32_t sh2, uint32_t sh3);
uint32_t pageMapCount(uint32_t root, uint32_t target);
uint32_t prepare(uint32_t root, uint32_t target, uint32_t list, uint32_t add_sh3);
uint32_t mapPage(uint32_t src, uint32_t root, uint32_t target, uint32_t r, uint32_t w, uint32_t x);
uint32_t notify2(uint32_t part, uint32_t int_no, uint32_t data1, uint32_t data2);
#define notify(part,no) notify2(part,no,0,0)
uint32_t dispatch(uint32_t part, uint32_t int_no, uint32_t data1, uint32_t data2);
uint32_t pip_time(void);
uint32_t resume(uint32_t desc, uint32_t ctx);
uint32_t viret(void);
#endif

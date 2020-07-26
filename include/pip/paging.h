#ifndef __PAGING__
#define __PAGING__

#include <stdint.h>

#define PGSIZE 0x1000
#define PGMASK (PGSIZE-1)

int Pip_InitPaging(uint32_t begin, uint32_t end);
void* Pip_AllocPage(void);
void Pip_FreePage(void* page);

#endif

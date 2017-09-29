#ifndef __PAGING__
#define __PAGING__

#include <stdint.h>

#define PGSIZE 0x1000
#define PGMASK (PGSIZE-1)

int Pip_InitPaging(void* begin, void* end);
void* Pip_AllocPage(void);
void Pip_FreePage(void* page);

#endif

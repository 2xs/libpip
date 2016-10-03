#ifndef __PAGING__
#define __PAGING__

#include <stdint.h>

#define PGSIZE 0x1000
#define PGMASK (PGSIZE-1)

int initPaging(void* begin, void* end);
void* allocPage(void);
void freePage(void* page);
int mapPageWrapper(void*va_src, void* partition, void*va_dest);

#endif

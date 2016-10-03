#include <stdint.h>
#include <pip/paging.h>
#include <pip/debug.h>
#include <pip/api.h>

#define NULL 0

void *first_freePage = NULL;

int
initPaging(void *begin, void *end)
{
	unsigned long p, b=(unsigned long)begin, e=(unsigned long)end, c=0;

	if (b >= e || (b & PGMASK) || (e & PGMASK))
		return -1;

	first_freePage = begin;

	for	( p = b + PGSIZE; p != e; p+=PGSIZE){
		*(void**)b = (void*)p;
		b = p;
		c += 1;
	}
	*(void**)b = (void*)0;

	puts("initPaging: "); putdec(c); puts(" pages available\n");
	return 0;
}

void* allocPage(void)
{
    void* ret = first_freePage;

    if (ret)
        first_freePage = *(void**)ret;
    else{
        puts("no more pages\n");
    }

    return ret;
}

void freePage(void* page)
{
    *(void**)page = first_freePage;
    first_freePage = page;
}

int mapPageWrapper(void* va_src, void* partition, void* va_dest)
{
	uint32_t i, count, *page, *tmp;

	if((count = pageMapCount((uint32_t)partition, (uint32_t)va_dest)) > 0)
	{
		page = allocPage();
		*(void**)page = (void*)0;

		for(i=0; i<count-1; i++){
			tmp = allocPage();
			*(void**)tmp = page;
			page = tmp;
		}

		if (!prepare((uint32_t)partition, (uint32_t)(va_dest), (uint32_t)page, 0x0))
		{
			puts("Prepare operation failed. Aborting.\n");
			return -1;
		}
	}
	if(!mapPage((uint32_t)va_src, (uint32_t)partition, (uint32_t)va_dest, 0x1, 0x1, 0x1)){
		puts("mapPage failed\n");
		return -1;
	}

	return 0;
}

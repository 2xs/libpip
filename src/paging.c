#include <stdint.h>
#include <pip/paging.h>
#include <pip/debug.h>
#include <pip/api.h>

#define NULL 0

void *Pager_FirstFreePage = NULL;

/* Initializes paging, depending on the addresses given */
int Pip_InitPaging(void *begin, void *end)
{
	unsigned long p, b=(unsigned long)begin, e=(unsigned long)end, c=0;

	if (b >= e || (b & PGMASK) || (e & PGMASK))
		return -1;

	Pager_FirstFreePage = begin;

	for	( p = b + PGSIZE; p != e; p+=PGSIZE){
		*(void**)b = (void*)p;
		b = p;
		c += 1;
	}
	*(void**)b = (void*)0;

    Pip_Debug_Puts("LibPip2 : Paging initialization complete. ");
    Pip_Debug_PutDec(c);
    Pip_Debug_Puts(" pages available.\n");

	return 0;
}

/* Allocates a page */
void* Pip_AllocPage(void)
{
    void* ret = Pager_FirstFreePage;

    if (ret) Pager_FirstFreePage = *(void**)ret;
    else ret = 0;

    return ret;
}

/* Frees a page */
void Pip_FreePage(void* page)
{
    *(void**)page = Pager_FirstFreePage;
    Pager_FirstFreePage = page;
}

#include <stdint.h>
#include <pip/paging.h>
#include <pip/stdio.h>
#include <pip/api.h>

#define NULL 0

void *Pager_FirstFreePage = NULL;

/* Initializes paging, depending on the addresses given */
int Pip_InitPaging(void *begin, void *end)
{
	unsigned long p, b=(unsigned long)begin, e=(unsigned long)end, c=0;

	if (b >= e || (b & PGMASK) || (e & PGMASK))
		return 0;

	Pager_FirstFreePage = begin;

	for (p = b + PGSIZE; p < e; p += PGSIZE)
	{
		*(void**)b = (void*)p;

		b = p;
		c += 1;
	}

	*(void**)b = (void*)0;

	return 1;
}

/* Allocates a page */
void* Pip_AllocPage(void)
{
	void* ret = Pager_FirstFreePage;

	if(!ret)
		return 0;

	Pager_FirstFreePage = *(void**)ret;

	for (int j = 0; j < PGSIZE; j++)
		((char *) ret)[j] = (char) 0;

	return ret;
}

/* Frees a page */
void Pip_FreePage(void* page)
{
	*(void**)page = Pager_FirstFreePage;
	Pager_FirstFreePage = page;
}

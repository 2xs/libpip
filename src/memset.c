#include "pip/stdio.h"

extern void *memset(void *dest, int val, unsigned long int len)
{
	unsigned char *ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return dest;
}

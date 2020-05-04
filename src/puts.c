#include "pip/stdio.h"

extern void puts(const char *msg)
{
	for (unsigned int i = 0; msg[i] != '\0'; i++)
	{
		putchar(msg[i]);
	}
}

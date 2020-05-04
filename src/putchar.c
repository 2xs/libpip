#include "pip/stdio.h"

extern void putchar(int c)
{
	Pip_Debug_Putc(c);
}

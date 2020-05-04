#include <pip/api.h>

#define SERIAL_PORT 0x3f8

void Pip_Debug_Putc(char c)
{
    while (!(Pip_Inb(SERIAL_PORT + 5) & 0x20));
    Pip_Outb(SERIAL_PORT, c);
}

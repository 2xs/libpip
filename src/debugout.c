#include "pip/debug.h"

void Pip_Debug_Puts(char *msg)
{
    while (*msg) Pip_Debug_Putc(*msg++);
}

#define H2C(n) ((n)<10?(n)+'0':(n)+'A'-10)
void Pip_Debug_PutHex(unsigned long n)
{
    int i;

    Pip_Debug_Putc('0'); Pip_Debug_Putc('x');
    for (i=0;i<8;i++){
        Pip_Debug_Putc(H2C((n>>28)&0xf));
        n<<=4;
    }
}

void Pip_Debug_PutDec(unsigned long n)
{
	char buf[16], *ptr = &buf[sizeof(buf)-1];

	if (!n){
		Pip_Debug_Putc('0');
		return;
	}

	for ( *ptr = 0; ptr > buf && n; n /= 10){
		*--ptr = '0'+(n%10);
	}

	Pip_Debug_Puts(ptr);
}

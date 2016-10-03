#include <pip/io.h>
#define SERIAL_PORT 0x3f8

void putc(char c)
{
    while (!(inb(SERIAL_PORT + 5) & 0x20));
    outb(SERIAL_PORT, c);
}

void puts(char *msg)
{
    while (*msg) putc(*msg++);
}

#define H2C(n) ((n)<10?(n)+'0':(n)+'A'-10)
void puthex(unsigned long n)
{
    int i;

    putc('0'); putc('x');
    for (i=0;i<8;i++){
        putc(H2C((n>>28)&0xf));
        n<<=4;
    }
}

void putdec(unsigned long n)
{
	char buf[16], *ptr = &buf[sizeof(buf)-1];

	if (!n){
		putc('0');
		return;
	}

	for ( *ptr = 0; ptr > buf && n; n /= 10){
		*--ptr = '0'+(n%10);
	}

	puts(ptr);
}

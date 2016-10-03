#ifndef DEF_DEBUG_H
#define DEF_DEBUG_H

void putc(char c);
void puts(char *msg);
void putdec(unsigned long n);
void puthex(unsigned long n);

#define RED() puts("\e[91m")
#define GREEN() puts("\e[92m")
#define BLUE() puts("\e[34m")
#define NOCOL() puts("\e[0m")

#endif

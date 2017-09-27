#ifndef DEF_DEBUG_H
#define DEF_DEBUG_H

void Pip_Debug_Putc(char c);
void Pip_Debug_Puts(char *msg);
void Pip_Debug_PutDec(unsigned long n);
void Pip_Debug_PutHex(unsigned long n);

#define RED() puts("\e[91m")
#define GREEN() puts("\e[92m")
#define BLUE() puts("\e[34m")
#define NOCOL() puts("\e[0m")

#endif

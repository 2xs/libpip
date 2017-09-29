#ifndef __APICALL_X86__
#define __APICALL_X86__

#include "pip/pipcall.h"
#include "pip/api.h"

/* Declare all sub-__Arch_APICall methods from a single macro */
#define __Arch_APICall(a, b, args...) __Arch_APICall_##b(a, args)

/* Those functions are implemeted in apicall.c */
uint32_t __Arch_APICall_0(uint32_t call);
uint32_t __Arch_APICall_1(uint32_t call, uint32_t a);
uint32_t __Arch_APICall_2(uint32_t call, uint32_t a, uint32_t b);
uint32_t __Arch_APICall_3(uint32_t call, uint32_t a, uint32_t b, uint32_t c);
uint32_t __Arch_APICall_4(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d);
uint32_t __Arch_APICall_5(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
uint32_t __Arch_APICall_6(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

/* Some x86-only calls, which entries could be used for something else on other architectures */
#define OUTB                (ARCH_DEPENDANT)
#define INB                 (ARCH_DEPENDANT + 1)
#define OUTW                (ARCH_DEPENDANT + 2)
#define INW                 (ARCH_DEPENDANT + 3)
#define OUTL                (ARCH_DEPENDANT + 4)
#define INL                 (ARCH_DEPENDANT + 5)
#define OUTADDRL            (ARCH_DEPENDANT + 6)

/* Extra pipcalls for x86 declaration */
#define Pip_Outb(a, b)         __Arch_APICall(OUTB, 2, a, b)
#define Pip_Inb(a)             __Arch_APICall(INB, 1, a)
#define Pip_Outw(a, b)         __Arch_APICall(OUTW, 2, a, b)
#define Pip_Inw(a)             __Arch_APICall(INW, 1, a)
#define Pip_Outl(a, b)         __Arch_APICall(OUTL, 2, a, b)
#define Pip_Inl(a)             __Arch_APICall(INL, 1, a)
#define Pip_Outaddrl(a, b)     __Arch_APICall(OUTADDRL, 2, a, b)

#endif

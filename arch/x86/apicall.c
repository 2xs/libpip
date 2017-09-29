#include "pip/pipcall.h"
#include "pip/api.h"
#include "pip/types.h"
#include "pip/calltable.h"

/* Architecture-dependant API call for x86 architecture
 * ---
 * Those methods follow exactly the same rules :
 * - First they get the appropriate Pipcall assembly stub from the call number given in parameters
 * - They return 0 if the call was not found (which shouldn't happen)
 * - They cast the pointer into an apicall_X function pointer, which takes the accurate number of arguments
 * - Then they do the call through an assembly stub, and return its correct value
 */
uint32_t __Arch_APICall_0(uint32_t call)
{
    apicall_0 callptr;
    switch(call)
    {
        case TIMER:
            callptr = pip_time;
            break;
        default:
            return 0;
    }

    return callptr();
}

uint32_t __Arch_APICall_1(uint32_t call, uint32_t a)
{
    apicall_1 callptr;
    switch(call)
    {
        case MAPPEDINCHILD:
            callptr = mappedInChild;
            break;
        case DELETEPARTITION:
            callptr = deletePartition;
            break;
        case COLLECT:
            callptr = collect;
            break;
        case INB:
            callptr = inb;
            break;
        case INW:
            callptr = inw;
            break;
        case INL:
            callptr = inl;
            break;
        default:
            return 0;
    }

    return callptr(a);
}
uint32_t __Arch_APICall_2(uint32_t call, uint32_t a, uint32_t b)
{
    apicall_2 callptr;
    switch(call)
    {
        case PAGECOUNT:
            callptr = pageMapCount;
            break;
        case RESUME:
            callptr = resume;
            break;
        case REMOVEVADDR:
            callptr = unmapPage;
            break;
        case OUTB:
            callptr = outb;
            break;
        case OUTW:
            callptr = outw;
            break;
        case OUTL:
            callptr = outl;
            break;
        case OUTADDRL:
            callptr = outaddrl;
            break;
        default:
            return 0;
    }

    return callptr(a, b);
}
uint32_t __Arch_APICall_3(uint32_t call, uint32_t a, uint32_t b, uint32_t c)
{
    return 0;
}
uint32_t __Arch_APICall_4(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    apicall_4 callptr;
    switch(call)
    {
        case PREPARE:
            callptr = prepare;
            break;
        default:
            return 0;
    }

    return callptr(a, b, c, d);
}
uint32_t __Arch_APICall_5(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    apicall_5 callptr;
    switch(call)
    {
        case CREATEPARTITION:
            callptr = createPartition;
            break;
        case DISPATCH:
            callptr = dispatch;
            break;
        default:
            return 0;
    }

    return callptr(a, b, c, d, e);
}

uint32_t __Arch_APICall_6(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    apicall_6 callptr;
    switch(call)
    {
        case ADDVADDR:
            callptr = mapPage;
            break;
        default:
            return 0;
    }

    return callptr(a, b, c, d, e, f);
}

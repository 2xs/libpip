#ifndef __API__
#define __API__

#include <stdint.h>
#include "pip/arch_api.h"

/* Raw API calls */

#define Pip_CreatePartition(a, b, c, d, e)  __Arch_APICall(CREATEPARTITION, 5, a, b, c, d, e)
#define Pip_PageCount(a, b)                 __Arch_APICall(PAGECOUNT, 2, a, b)
#define Pip_Prepare(a, b, c, d)             __Arch_APICall(PREPARE, 4, a, b, c, d)
#define Pip_AddVAddr(a, b, c, d, e, f)      __Arch_APICall(ADDVADDR, 6, a, b, c, d, e, f)
#define Pip_Dispatch(a, b, c, d, e)         __Arch_APICall(DISPATCH, 5, a, b, c, d, e)
#define Pip_Timer                           __Arch_APICall(TIMER, 0)
#define Pip_Resume(a, b)                    __Arch_APICall(RESUME, 2, a, b)
#define Pip_RemoveVAddr(a, b)               __Arch_APICall(REMOVEVADDR, 2, a, b)
#define Pip_MappedInChild(a)                __Arch_APICall(MAPPEDINCHILD, 1, a)
#define Pip_DeletePartition(a)              __Arch_APICall(DELETEPARTITION, 1, a)
#define Pip_Collect(a)                      __Arch_APICall(COLLECT, 1, a)

/* Wrappers */
uint32_t Pip_MapPageWrapper(uint32_t source, uint32_t partition, uint32_t destination);
uint32_t Pip_Notify(uint32_t destination, uint32_t int_no, uint32_t data1, uint32_t data2);

#endif

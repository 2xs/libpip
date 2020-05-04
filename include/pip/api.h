#ifndef __API__
#define __API__

#include <stdint.h>
#include "pip/arch_api.h"

/* Raw API calls */

#define Pip_CreatePartition(a, b, c, d, e)  __Arch_APICall(CREATEPARTITION, 5, a, b, c, d, e)
#define Pip_CountToMap(a, b)                __Arch_APICall(COUNTTOMAP, 2, a, b)
#define Pip_Prepare(a, b, c, d)             __Arch_APICall(PREPARE, 4, a, b, c, d)
#define Pip_AddVAddr(a, b, c, d, e, f)      __Arch_APICall(ADDVADDR, 6, a, b, c, d, e, f)
#define Pip_Get_Int_State(a)                __Arch_APICall(GET_INT_STATE, 1, a)
#define Pip_Set_Int_State(a)                __Arch_APICall(SET_INT_STATE, 1, a)
#define Pip_RemoveVAddr(a, b)               __Arch_APICall(REMOVEVADDR, 2, a, b)
#define Pip_MappedInChild(a)                __Arch_APICall(MAPPEDINCHILD, 1, a)
#define Pip_DeletePartition(a)              __Arch_APICall(DELETEPARTITION, 1, a)
#define Pip_Collect(a)                      __Arch_APICall(COLLECT, 1, a)
#define Pip_Yield(a, b, c, d, e)            __Arch_APICall(YIELD, 5, a, b, c, d, e)

/* Wrappers */

#define R	0x1
#define W	0x2
#define E	0x4

uint32_t Pip_MapPageWrapper(uint32_t source, uint32_t partition, uint32_t destination/*, uint32_t rigths*/);

/*uint32_t Pip_MapPageWrapper_RONLY(uint32_t source, uint32_t partition, uint32_t destination);
uint32_t Pip_Notify(uint32_t destination, uint32_t int_no, uint32_t data1, uint32_t data2);*/

#endif

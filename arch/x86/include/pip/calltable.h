#ifndef __CALLTABLE__
#define __CALLTABLE__

#include "pip/pipcall.h"
#include "pip/api.h"
#include "pip/types.h"

/* All the functions declared here are implemented in farcall.S */ 

/* Assembly stubs for API calls */
extern uint32_t pip_time();

extern uint32_t mappedInChild(uint32_t);
extern uint32_t deletePartition(uint32_t);
extern uint32_t collect(uint32_t);

extern uint32_t unmapPage(uint32_t, uint32_t);
extern uint32_t resume(uint32_t, uint32_t);
extern uint32_t pageMapCount(uint32_t, uint32_t);

extern uint32_t prepare(uint32_t, uint32_t, uint32_t, uint32_t);

extern uint32_t dispatch(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t); 
extern uint32_t createPartition(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t); 

extern uint32_t mapPage(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t); 

/* IO ports calls - x86 */
extern uint32_t inb(uint32_t);
extern uint32_t inw(uint32_t);
extern uint32_t inl(uint32_t);

extern uint32_t outb(uint32_t, uint32_t);
extern uint32_t outw(uint32_t, uint32_t);
extern uint32_t outl(uint32_t, uint32_t);
extern uint32_t outaddrl(uint32_t, uint32_t);

#endif

#include <stdint.h>
#include <pip/vidt.h>

extern void resumeHandler(void);

void registerIntBase(vidt_t *vidt, uint32_t intno, void* handler, uint32_t* stack)
{
	vidt->vint[intno].eip = (uint32_t)handler;
	vidt->vint[intno].esp = (uint32_t)stack;
}

void registerInterrupt(uint32_t intno, void* handler, uint32_t* stack)
{
	registerIntBase(CURRENT_VIDT, intno, handler, stack);
}

void vcli(void)
{
	CURRENT_VIDT->flags |= 1;
}

void vsti(void)
{
	CURRENT_VIDT->flags &= ~1;
}

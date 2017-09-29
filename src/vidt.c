#include <stdint.h>
#include <pip/vidt.h>

void registerIntBase(vidt_t *vidt, uint32_t intno, void* handler, uint32_t* stack)
{
	vidt->vint[intno].eip = (uint32_t)handler;
	vidt->vint[intno].esp = (uint32_t)stack;
}

void Pip_RegisterInterrupt(uint32_t intno, void* handler, uint32_t* stack)
{
	registerIntBase(CURRENT_VIDT, intno, handler, stack);
}

void Pip_VCLI(void)
{
	CURRENT_VIDT->flags |= 1;
}

void Pip_VSTI(void)
{
	CURRENT_VIDT->flags &= ~1;
}

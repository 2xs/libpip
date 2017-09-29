#include "pip/api.h"
#include "pip/arch_api.h"
#include "pip/paging.h"
#include "pip/debug.h"

uint32_t Pip_MapPageWrapper(uint32_t source, uint32_t partition, uint32_t destination)
{
	uint32_t i, count, *page, *tmp;

	if((count = Pip_PageCount((uint32_t)partition, (uint32_t)destination)) > 0)
	{
		page = Pip_AllocPage();
		*(void**)page = (void*)0;

		for(i=0; i<count-1; i++){
			tmp = Pip_AllocPage();
			*(void**)tmp = page;
			page = tmp;
		}

		if (!Pip_Prepare((uint32_t)partition, (uint32_t)(destination), (uint32_t)page, 0x0))
		{
			Pip_Debug_Puts("LibPip2 : Prepare operation failed. Aborting page map.\n");
			return -1;
		}
	}
	if(!Pip_AddVAddr((uint32_t)source, (uint32_t)partition, (uint32_t)destination, 0x1, 0x1, 0x1)){
		Pip_Debug_Puts("LibPip2 : MapPage operation failed.\n");
		return -1;
	}

	return 0;
}

uint32_t Pip_Notify(uint32_t destination, uint32_t int_no, uint32_t data1, uint32_t data2)
{
    return Pip_Dispatch(destination, int_no, 0, data1, data2);
}

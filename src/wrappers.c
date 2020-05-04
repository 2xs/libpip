#include "pip/arch_api.h"
#include "pip/paging.h"

extern uint32_t
Pip_MapPageWrapper(uint32_t source, uint32_t partition, uint32_t destination/*, uint32_t rights*/)
{
	uint32_t i, count, *page, *current;
	/*uint8_t r, w, e;*/

	if ((count = Pip_CountToMap(partition, destination)) > 0)
	{
		page = Pip_AllocPage();

		*(void**) page = (void*) 0;

		for (i = 0; i < count - 1; i++)
		{
			current = Pip_AllocPage();
			*(void**) current = page;
			page = current;
		}

		if (!Pip_Prepare(partition, destination, (uint32_t) page, 0x0))
		{
			return 0;
		}
	}

	/*r =  rights       & 1;
	w = (rights >> 1) & 1;
	e = (rights >> 2) & 1;*/

	if (!Pip_AddVAddr(source, partition, destination, 1, 1, 1))
	{
		return 0;
	}

	return 1;
}

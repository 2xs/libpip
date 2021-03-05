#include "pip/arch_api.h"
#include "pip/paging.h"
#include "pip/piptypes.h"
#include "pip/wrappers.h"

extern uint32_t
Pip_MapPageWrapper(uint32_t source, uint32_t partition, uint32_t destination)
{
	uint32_t i, count, *page, *current;

	// count can fail if it not a valid partition descriptor
	// but returns 0
	if ((count = Pip_CountToMap(partition, destination)) > 0)
	{
		// can fail if there is no page left in the allocator
		page = Pip_AllocPage();
		if (page == NULL) {
			return FAIL_ALLOC_PAGE;
		}

		*(void**) page = (void*) 0;

		for (i = 0; i < count - 1; i++)
		{
			current = Pip_AllocPage();
			if (current == NULL) {
				return FAIL_ALLOC_PAGE;
			}

			*(void**) current = page;
			page = current;
		}

		// can fail if :
		//  - the partition descriptor is not a valid child descriptor
		//  - not enough pages inside the linked list
		// returns a boolvaddr
		// least significant bit is whether the call succeeded or not
		uint32_t prepare_ret_value = Pip_Prepare(partition, destination, (uint32_t) page);
		if (!prepare_success(prepare_ret_value))
		{
			return FAIL_PREPARE;
		}
	}

	if (!Pip_AddVAddr(source, partition, destination, 1, 1, 1))
	{
		return FAIL_ADD_VADDR;
	}

	return SUCCESS;
}

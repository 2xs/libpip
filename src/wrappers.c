/*******************************************************************************/
/*  © Université de Lille, The Pip Development Team (2015-2021)                */
/*                                                                             */
/*  This software is a computer program whose purpose is to run a minimal,     */
/*  hypervisor relying on proven properties such as memory isolation.          */
/*                                                                             */
/*  This software is governed by the CeCILL license under French law and       */
/*  abiding by the rules of distribution of free software.  You can  use,      */
/*  modify and/ or redistribute the software under the terms of the CeCILL     */
/*  license as circulated by CEA, CNRS and INRIA at the following URL          */
/*  "http://www.cecill.info".                                                  */
/*                                                                             */
/*  As a counterpart to the access to the source code and  rights to copy,     */
/*  modify and redistribute granted by the license, users are provided only    */
/*  with a limited warranty  and the software's author,  the holder of the     */
/*  economic rights,  and the successive licensors  have only  limited         */
/*  liability.                                                                 */
/*                                                                             */
/*  In this respect, the user's attention is drawn to the risks associated     */
/*  with loading,  using,  modifying and/or developing or reproducing the      */
/*  software by the user in light of its specific status of free software,     */
/*  that may mean  that it is complicated to manipulate,  and  that  also      */
/*  therefore means  that it is reserved for developers  and  experienced      */
/*  professionals having in-depth computer knowledge. Users are therefore      */
/*  encouraged to load and test the software's suitability as regards their    */
/*  requirements in conditions enabling the security of their systems and/or   */
/*  data to be ensured and,  more generally, to use and operate it in the      */
/*  same conditions as regards security.                                       */
/*                                                                             */
/*  The fact that you are presently reading this means that you have had       */
/*  knowledge of the CeCILL license and that you accept its terms.             */
/*******************************************************************************/

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

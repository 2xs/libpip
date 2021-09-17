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

#include "pip/pipcall.h"
#include "pip/api.h"
#include "pip/types.h"
#include "pip/calltable.h"

/* Architecture-dependant API call for ARMv7 architecture
 * ---
 * Those methods follow exactly the same rules :
 * - First they get the appropriate Pipcall assembly stub from the call number given in parameters
 * - They return 0 if the call was not found (which shouldn't happen)
 * - They cast the pointer into an apicall_X function pointer, which takes the accurate number of arguments
 * - Then they do the call through an assembly stub, and return its correct value
 */

uint32_t __Arch_APICall_0(uint32_t call)
{
	return 0;
}

uint32_t __Arch_APICall_1(uint32_t call, uint32_t a)
{
	apicall_1 callptr;

	switch(call)
	{
		case GET_INT_STATE:
			callptr = get_int_state;
			break;
		case SET_INT_STATE:
			callptr = set_int_state;
			break;
		case MAPPEDINCHILD:
			callptr = mappedInChild;
			break;
		case DELETEPARTITION:
			callptr = deletePartition;
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
		case COUNTTOMAP:
			callptr = countToMap;
			break;
		case REMOVEVADDR:
			callptr = removeVAddr;
			break;
		case COLLECT:
			callptr = collect;
			break;
		default:
			return 0;
	}

	return callptr(a, b);
}

uint32_t __Arch_APICall_3(uint32_t call, uint32_t a, uint32_t b,
	uint32_t c)
{
	apicall_3 callptr;

	switch(call)
	{
		case PREPARE:
			callptr = prepare;
			break;
		default:
			return 0;
	}

	return callptr(a, b, c);
}

uint32_t __Arch_APICall_4(uint32_t call, uint32_t a, uint32_t b,
	uint32_t c, uint32_t d)
{
	return 0;
}

uint32_t __Arch_APICall_5(uint32_t call, uint32_t a, uint32_t b,
	uint32_t c, uint32_t d, uint32_t e)
{
	apicall_5 callptr;

	switch(call)
	{
		case CREATEPARTITION:
			callptr = createPartition;
			break;
		case YIELD:
			callptr = yield;
			break;
		default:
			return 0;
	}

	return callptr(a, b, c, d, e);
}

uint32_t __Arch_APICall_6(uint32_t call, uint32_t a, uint32_t b,
	uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
	apicall_6 callptr;

	switch(call)
	{
		case ADDVADDR:
			callptr = addVAddr;
			break;
		default:
			return 0;
	}

	return callptr(a, b, c, d, e, f);
}

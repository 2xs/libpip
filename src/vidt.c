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

#include <stdint.h>

#include "pip/api.h"
#include "pip/stdio.h"
#include "pip/paging.h"
#include "pip/vidt.h"

user_ctx_t *Pip_AllocContext(void)
{
	static uint32_t availableBytes = sizeof(user_ctx_t);
	static uint32_t contextAddress = 0;

	availableBytes -= sizeof(user_ctx_t);

	if (availableBytes == 0)
	{
		contextAddress = (uint32_t) Pip_AllocPage();
		availableBytes = PAGE_SIZE;
	}
	else
	{
		contextAddress += sizeof(user_ctx_t);
	}

	return (user_ctx_t *) contextAddress;
}

void Pip_Notify(uint32_t calleePartDescVAddr, uint32_t calleeVidtVAddr,
		uint32_t userTargetInterrupt)
{
	VIDT[1023] = (user_ctx_t *) calleePartDescVAddr;

	if (calleePartDescVAddr != 0)
	{
		((user_ctx_t **) calleeVidtVAddr)[1023] =  (user_ctx_t *) 0;
	}

	Pip_Yield(calleePartDescVAddr, userTargetInterrupt, 70, 0, 0);
}

void Pip_Resume(void)
{
	Pip_Yield((uint32_t) VIDT[1023], 70, 255, 0, 0);
}

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
#include <pip/paging.h>
#include <pip/stdio.h>
#include <pip/api.h>

#define NULL 0

void *Pager_FirstFreePage = NULL;

int Pip_InitPaging(uint32_t begin, uint32_t end)
{
	uint32_t p, b = begin, e = end, c = 0;

	if (b >= e || (b & PGMASK) || (e & PGMASK))
	{
		return 0;
	}

	Pager_FirstFreePage = (void *) begin;

	for (p = b + PGSIZE; p < e; p += PGSIZE)
	{
		*(void**)b = (void*)p;

		b = p;
		c += 1;
	}

	*(void**)b = (void*)0;

	return 1;
}

void* Pip_AllocPage(void)
{
	void* ret = Pager_FirstFreePage;

	if(!ret)
		return 0;

	Pager_FirstFreePage = *(void**)ret;

	for (int j = 0; j < PGSIZE; j++)
	{
		((char *) ret)[j] = (char) 0;
	}

	return ret;
}

void Pip_FreePage(void* page)
{
	*(void**)page = Pager_FirstFreePage;
	Pager_FirstFreePage = page;
}

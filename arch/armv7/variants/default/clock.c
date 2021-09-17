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

uint64_t __clock_gettime(void)
{
	uint32_t pmccntr, pmuseren, pmcntenset;

	/* ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition
	 * c9, Count Enable Set Register (PMCNTENSET)
	 *
	 * The PMCNTENSET register is accessible in user mode only when the
	 * PMUSERENR.EN bit is set to 1
	 */

	asm volatile
	(
		 "mrc p15, 0, %0, c9, c14, 0"
		 : "=r" (pmuseren)
	);

	if (pmuseren & 1)
	{
		/* ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition
		 * c9, Count Enable Set Register (PMCNTENSET)
		 *
		 * The PMCNTENSET register is counting only when the C bit is
		 * set
		 */

		asm volatile
		(
			 "mrc p15, 0, %0, c9, c12, 1"
			 : "=r" (pmcntenset)
		);

		if (pmcntenset & 0x80000000ul)
		{
			asm volatile
			(
				 "mrc p15, 0, %0, c9, c13, 0"
				 : "=r" (pmccntr)
			);

			return (uint64_t)(pmccntr) << 6;
		}
	}

	return 0;
}

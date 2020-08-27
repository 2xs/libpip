/*******************************************************************************/
/*  © Université Lille 1, The Pip Development Team (2015-2020)                 */
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

#include "pip/stdio.h"
#include "pip/time.h"
#include "pip/api.h"

/*!
 * \brief Read the time stamp counter using the rdtsc instruction
 * \return The number of cycles since the last CPU reset
 */
static uint64_t __rdtsc(void)
{
	uint32_t cyclesLow, cyclesHigh;

	asm volatile
	(
		"rdtsc;"
		"mov %%edx, %0;"
		"mov %%eax, %1"
		: "=r" (cyclesHigh), "=r" (cyclesLow)
		:: "eax", "edx"
	);

	return (((uint64_t) cyclesHigh << 32) | cyclesLow);
}

/*!
 * \brief Read the time stamp counter using the rdtsc instruction
 * \param Where to store the number of cycles since the last CPU reset
 * \return The number of cycles since the last CPU reset
 */
extern uint64_t time(uint64_t *t)
{
	uint64_t timestamp = __rdtsc();

	if (t)
	{
		*t = timestamp;
	}

	return timestamp;
}

/*!
 * \brief Print a 64-bits value
 * \param val The 64-bits value to print
 */
extern void print64(uint64_t val)
{
	static char buf[34] = { [0 ... 33] = 0 };
	unsigned int hbase = 10;
	char* out = &buf[33];
	uint64_t hval = val;

	do
	{
		*out = "0123456789"[hval % hbase];
		--out;
		hval /= hbase;
	} while(hval);

	*out-- = ' ', *out = ' ';

	puts(out);
}
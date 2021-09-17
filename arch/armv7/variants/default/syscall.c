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

uint32_t createPartition(uint32_t a, uint32_t b, uint32_t c,
	uint32_t d, uint32_t e)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;
	register uint32_t r2 asm("r2") = c;
	register uint32_t r3 asm("r3") = d;
	register uint32_t r4 asm("r4") = e;

	asm volatile
	(
		 "svc #0"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1),
		 "r"  (r2),
		 "r"  (r3),
		 "r"  (r4)
		 : "memory"
	);

	return r0;
}

uint32_t countToMap(uint32_t a, uint32_t b)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;

	asm volatile
	(
		 "svc #1"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1)
		 : "memory"
	);

	return r0;
}

uint32_t prepare(uint32_t a, uint32_t b, uint32_t c)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;
	register uint32_t r2 asm("r2") = c;

	asm volatile
	(
		 "svc #2"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1),
		 "r"  (r2)
		 : "memory"
	);

	return r0;
}

uint32_t addVAddr(uint32_t a, uint32_t b, uint32_t c,
	uint32_t d, uint32_t e, uint32_t f)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;
	register uint32_t r2 asm("r2") = c;
	register uint32_t r3 asm("r3") = d;
	register uint32_t r4 asm("r4") = e;
	register uint32_t r5 asm("r5") = f;

	asm volatile
	(
		 "svc #3"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1),
		 "r"  (r2),
		 "r"  (r3),
		 "r"  (r4),
		 "r"  (r5)
		 : "memory"
	);

	return r0;
}

uint32_t get_int_state(uint32_t a)
{
	register uint32_t r0 asm("r0") = a;

	asm volatile
	(
		 "svc #4"
		 : "=r" (r0)
		 : "0"  (r0)
		 : "memory"
	);

	return r0;
}

uint32_t set_int_state(uint32_t a)
{
	register uint32_t r0 asm("r0") = a;

	asm volatile
	(
		 "svc #5"
		 : "=r" (r0)
		 : "0"  (r0)
		 : "memory"
	);

	return r0;
}

uint32_t removeVAddr(uint32_t a, uint32_t b)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;

	asm volatile
	(
		 "svc #6"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1)
		 : "memory"
	);

	return r0;
}

uint32_t mappedInChild(uint32_t a)
{
	register uint32_t r0 asm("r0") = a;

	asm volatile
	(
		 "svc #7"
		 : "=r" (r0)
		 : "0"  (r0)
		 : "memory"
	);

	return r0;
}

uint32_t deletePartition(uint32_t a)
{
	register uint32_t r0 asm("r0") = a;

	asm volatile
	(
		 "svc #8"
		 : "=r" (r0)
		 : "0"  (r0)
		 : "memory"
	);

	return r0;
}

uint32_t collect(uint32_t a, uint32_t b)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;

	asm volatile
	(
		 "svc #9"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1)
		 : "memory"
	);

	return r0;
}

uint32_t yield(uint32_t a, uint32_t b, uint32_t c,
	uint32_t d, uint32_t e)
{
	register uint32_t r0 asm("r0") = a;
	register uint32_t r1 asm("r1") = b;
	register uint32_t r2 asm("r2") = c;
	register uint32_t r3 asm("r3") = d;
	register uint32_t r4 asm("r4") = e;

	asm volatile
	(
		 "svc #10"
		 : "=r" (r0)
		 : "0"  (r0),
		 "r"  (r1),
		 "r"  (r2),
		 "r"  (r3),
		 "r"  (r4)
		 : "memory"
	);

	return r0;
}

uint32_t serial_putchar(uint32_t a)
{
	register uint32_t r0 asm("r0") = a;

	asm volatile
	(
		 "svc #11"
		 : "=r" (r0)
		 : "0"  (r0)
		 : "memory"
	);

	return r0;
}

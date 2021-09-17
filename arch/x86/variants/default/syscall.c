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
#include <pip/stdio.h>

uint32_t outb(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	0xfffffffc;"
		 "orl	$1,0xfffffffc;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x30,$0x0;"
		 "add	$0x8,%%esp;"
		 "pop	0xfffffffc;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t inb(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	0xfffffffc;"
		 "orl	$1,0xfffffffc;"
		 "push	%1;"
		 "lcall	$0x38,$0x0;"
		 "add	$0x4,%%esp;"
		 "pop	0xfffffffc;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t outw(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	0xfffffffc;"
		 "orl	$1,0xfffffffc;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x40,$0x0;"
		 "add	$0x8,%%esp;"
		 "pop	0xfffffffc;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t inw(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	0xfffffffc;"
		 "orl	$1,0xfffffffc;"
		 "push	%1;"
		 "lcall	$0x48,$0x0;"
		 "add	$0x4,%%esp;"
		 "pop	0xfffffffc;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t outl(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	0xfffffffc;"
		 "orl	$1,0xfffffffc;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x50,$0x0;"
		 "add	$0x8,%%esp;"
		 "pop	0xfffffffc;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t inl(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	0xfffffffc;"
		 "orl	$1,0xfffffffc;"
		 "push	%1;"
		 "lcall	$0x58,$0x0;"
		 "add	$0x4,%%esp;"
		 "pop	0xfffffffc;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t createPartition(uint32_t a, uint32_t b, uint32_t c,
	uint32_t d, uint32_t e)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%5;"
		 "push	%4;"
		 "push	%3;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x60,$0x0;"
		 "add	$0x14,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b),
		 "r" (c),
		 "r" (d),
		 "r" (e)
		 :
	);

	return r;
}

uint32_t countToMap(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x68,$0x0;"
		 "add	$0x8,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t prepare(uint32_t a, uint32_t b, uint32_t c)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%3;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x70,$0x0;"
		 "add	$0xC,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b),
		 "r" (c)
		 :
	);

	return r;
}

uint32_t addVAddr(uint32_t a, uint32_t b, uint32_t c,
	uint32_t d, uint32_t e, uint32_t f)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%6;"
		 "push	%5;"
		 "push	%4;"
		 "push	%3;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x78,$0x0;"
		 "add	$0x18,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b),
		 "r" (c),
		 "r" (d),
		 "r" (e),
		 "r" (f)
		 :
	);

	return r;
}

uint32_t get_int_state(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%1;"
		 "lcall	$0x80,$0x0;"
		 "add	$0x4,%%esp;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t outaddrl(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0x88,$0x0;"
		 "add	$0x8,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t set_int_state(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%1;"
		 "lcall	$0x98,$0x0;"
		 "add	$0x4,%%esp;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t removeVAddr(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0xa0,$0x0;"
		 "add	$0x8,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t mappedInChild(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%1;"
		 "lcall	$0xa8,$0x0;"
		 "add	$0x4,%%esp;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t deletePartition(uint32_t a)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%1;"
		 "lcall	$0xb0,$0x0;"
		 "add	$0x4,%%esp;"
		 : "=r" (r)
		 : "r" (a)
		 :
	);

	return r;
}

uint32_t collect(uint32_t a, uint32_t b)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0xb8,$0x0;"
		 "add	$0x8,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b)
		 :
	);

	return r;
}

uint32_t yield(uint32_t a, uint32_t b, uint32_t c,
	uint32_t d, uint32_t e)
{
	register uint32_t r asm("eax");

	asm volatile
	(
		 "push	%5;"
		 "push	%4;"
		 "push	%3;"
		 "push	%2;"
		 "push	%1;"
		 "lcall	$0xc0,$0x0;"
		 "add	$0x14,%%esp;"
		 : "=r" (r)
		 : "r" (a),
		 "r" (b),
		 "r" (c),
		 "r" (d),
		 "r" (e)
		 :
	);

	return r;
}

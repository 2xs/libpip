#include <stdint.h>
#include <pip/stdio.h>

extern uint32_t outb(uint32_t a, uint32_t b)
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

extern uint32_t inb(uint32_t a)
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

extern uint32_t outw(uint32_t a, uint32_t b)
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

extern uint32_t inw(uint32_t a)
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

extern uint32_t outl(uint32_t a, uint32_t b)
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

extern uint32_t inl(uint32_t a)
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

extern uint32_t createPartition(uint32_t a, uint32_t b,
	uint32_t c, uint32_t d, uint32_t e)
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

extern uint32_t countToMap(uint32_t a, uint32_t b)
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

extern uint32_t prepare(uint32_t a, uint32_t b,
	uint32_t c)
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

extern uint32_t addVAddr(uint32_t a, uint32_t b,
	uint32_t c, uint32_t d, uint32_t e, uint32_t f)
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

extern uint32_t get_int_state(uint32_t a)
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

extern uint32_t outaddrl(uint32_t a, uint32_t b)
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

extern uint32_t set_int_state(uint32_t a)
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

extern uint32_t removeVAddr(uint32_t a, uint32_t b)
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

extern uint32_t mappedInChild(uint32_t a)
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

extern uint32_t deletePartition(uint32_t a)
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

extern uint32_t collect(uint32_t a, uint32_t b)
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

extern uint32_t yield(uint32_t a, uint32_t b,
	uint32_t c, uint32_t d, uint32_t e)
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

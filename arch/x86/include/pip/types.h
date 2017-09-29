#ifndef __TYPES__
#define __TYPES__

#include <stdint.h>

/* Pipcall function pointer types */
typedef uint32_t (*apicall_0)();
typedef uint32_t (*apicall_1)(uint32_t a);
typedef uint32_t (*apicall_2)(uint32_t a, uint32_t b);
typedef uint32_t (*apicall_3)(uint32_t a, uint32_t b, uint32_t c);
typedef uint32_t (*apicall_4)(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
typedef uint32_t (*apicall_5)(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
typedef uint32_t (*apicall_6)(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

#endif

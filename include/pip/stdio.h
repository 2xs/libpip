#ifndef DEF_DEBUG_H
#define DEF_DEBUG_H

#include <stdint.h>

void Pip_Debug_Putc(char c);

extern void putchar(int c);
extern void puts(const char *msg);
extern void printf(const char *format, ...);
extern void *memset(void *dest, int val, unsigned long int len);

#define RED() puts("\e[91m")
#define GREEN() puts("\e[92m")
#define BLUE() puts("\e[34m")
#define NOCOL() puts("\e[0m")



#define PIP_DEBUG_MODE 1

#define CRITICAL	1 //!< Critical output
#define	ERROR		2 //!< Error output
#define WARNING		3 //!< Warning output
#define	INFO		4 //!< Information output
#define LOG		    5 //!< Log output
#define TRACE		6 //!< Annoying, verbose output

#define True 1
#define False 0


#ifndef LOGLEVEL
#define LOGLEVEL INFO
#endif

/**
 * \brief Defines the appropriate DEBUGRAW behavior.
 */
#define DEBUGRAW(a) krn_puts(a)

/**
 * \brief Defines the appropriate DEBUG behavior.
 */
#define DEBUG(l,a,...) if(l <= LOGLEVEL){printf(#l "PARTITION [%s:%d]" a "\r\n", __FILE__, __LINE__, ##__VA_ARGS__);}
/* #define DEBUG(l,a) { krn_puts(debugstr[l]); krn_puts("["); krn_puts(__FILE__); krn_puts(":"); putdec(__LINE__); krn_puts("] "); krn_puts(a);} */
#define IAL_DEBUG(l,a,...) if(l<=LOGLEVEL){ printf(#l " IAL [%s:%d] " a "\r\n", __FILE__, __LINE__, ##__VA_ARGS__);}
/**
 * \brief Defines the appropriate DEBUGHEX behavior.
 */
#define DEBUGHEX(a) puthex(a)
/**
 * \brief Defines the appropriate DEBUGDEC behavior.
 */
#define DEBUGDEC(a) putdec(a)




#define BENCH_BEGIN counter_update(1)
#define BENCH_END {counter_update(0); DEBUG(TRACE, "Benchmark lasted "); display_time();}


#endif

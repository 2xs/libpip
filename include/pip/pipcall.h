#ifndef __PIPCALL__
#define __PIPCALL__

#define ARCH_INDEPENDANT    0
#define ARCH_DEPENDANT      12
/* Architecture-independant entries */
#define CREATEPARTITION     (ARCH_INDEPENDANT)
#define COUNTTOMAP          (ARCH_INDEPENDANT +  1)
#define PREPARE             (ARCH_INDEPENDANT +  2)
#define ADDVADDR            (ARCH_INDEPENDANT +  3)
#define GET_INT_STATE       (ARCH_INDEPENDANT +  4)
#define SET_INT_STATE       (ARCH_INDEPENDANT +  5)
#define REMOVEVADDR         (ARCH_INDEPENDANT +  6)
#define MAPPEDINCHILD       (ARCH_INDEPENDANT +  7)
#define DELETEPARTITION     (ARCH_INDEPENDANT +  8)
#define COLLECT             (ARCH_INDEPENDANT +  9)
#define YIELD               (ARCH_INDEPENDANT + 10)
#define SMPREQUEST          (ARCH_INDEPENDANT + 11)
#endif

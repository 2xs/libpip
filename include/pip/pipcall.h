#ifndef __PIPCALL__
#define __PIPCALL__

#define ARCH_INDEPENDANT    0
#define ARCH_DEPENDANT      11

/* Architecture-independant entries */
#define CREATEPARTITION     (ARCH_INDEPENDANT)
#define PAGECOUNT           (ARCH_INDEPENDANT + 1)
#define PREPARE             (ARCH_INDEPENDANT + 2)
#define ADDVADDR            (ARCH_INDEPENDANT + 3)
#define DISPATCH            (ARCH_INDEPENDANT + 4)
#define TIMER               (ARCH_INDEPENDANT + 5)
#define RESUME              (ARCH_INDEPENDANT + 6)
#define REMOVEVADDR         (ARCH_INDEPENDANT + 7)
#define MAPPEDINCHILD       (ARCH_INDEPENDANT + 8)
#define DELETEPARTITION     (ARCH_INDEPENDANT + 9)
#define COLLECT             (ARCH_INDEPENDANT + 10)

#endif

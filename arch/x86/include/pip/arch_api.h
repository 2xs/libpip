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

#ifndef __APICALL_X86__
#define __APICALL_X86__

#include "pip/pipcall.h"
#include "pip/api.h"

/* Declare all sub-__Arch_APICall methods from a single macro */
#define __Arch_APICall(a, b, args...) __Arch_APICall_##b(a, args)

/* Those functions are implemeted in apicall.c */
uint32_t __Arch_APICall_0(uint32_t call);
uint32_t __Arch_APICall_1(uint32_t call, uint32_t a);
uint32_t __Arch_APICall_2(uint32_t call, uint32_t a, uint32_t b);
uint32_t __Arch_APICall_3(uint32_t call, uint32_t a, uint32_t b, uint32_t c);
uint32_t __Arch_APICall_4(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d);
uint32_t __Arch_APICall_5(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
uint32_t __Arch_APICall_6(uint32_t call, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

/* Some x86-only calls, which entries could be used for something else on other architectures */
#define OUTB      (ARCH_DEPENDANT)
#define INB       (ARCH_DEPENDANT + 1)
#define OUTW      (ARCH_DEPENDANT + 2)
#define INW       (ARCH_DEPENDANT + 3)
#define OUTL      (ARCH_DEPENDANT + 4)
#define INL       (ARCH_DEPENDANT + 5)
#define OUTADDRL  (ARCH_DEPENDANT + 6)

/* Extra pipcalls for x86 declaration */
#define Pip_Outb(a, b)      __Arch_APICall(OUTB, 2, a, b)
#define Pip_Inb(a)          __Arch_APICall(INB, 1, a)
#define Pip_Outw(a, b)      __Arch_APICall(OUTW, 2, a, b)
#define Pip_Inw(a)          __Arch_APICall(INW, 1, a)
#define Pip_Outl(a, b)      __Arch_APICall(OUTL, 2, a, b)
#define Pip_Inl(a)          __Arch_APICall(INL, 1, a)
#define Pip_Outaddrl(a, b)  __Arch_APICall(OUTADDRL, 2, a, b)

/*
 * TODO
 */
#define Pip_MapPageWrapper(source, partition, destination) \
	Pip_MapPageWrapperFlags(source, partition, destination, 7)

#endif /* __APICALL_X86__ */

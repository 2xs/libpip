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

#ifndef __CALLTABLE_X86__
#define __CALLTABLE_X86__

#include "pip/pipcall.h"
#include "pip/api.h"
#include "pip/types.h"

/* All the functions declared here are implemented in syscall.c */

uint32_t createPartition(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
uint32_t countToMap(uint32_t, uint32_t);
uint32_t prepare(uint32_t, uint32_t, uint32_t);
uint32_t addVAddr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
uint32_t get_int_state(uint32_t);
uint32_t set_int_state(uint32_t);
uint32_t removeVAddr(uint32_t, uint32_t);
uint32_t mappedInChild(uint32_t);
uint32_t deletePartition(uint32_t);
uint32_t collect(uint32_t, uint32_t);
uint32_t yield(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

/* IO ports calls - x86 */

uint32_t inb(uint32_t);
uint32_t inw(uint32_t);
uint32_t inl(uint32_t);

uint32_t outb(uint32_t, uint32_t);
uint32_t outw(uint32_t, uint32_t);
uint32_t outl(uint32_t, uint32_t);
uint32_t outaddrl(uint32_t, uint32_t);

#endif /* __CALLTABLE_X86__ */

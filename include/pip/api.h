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

#ifndef __API__
#define __API__

#include <stdint.h>
#include "pip/arch_api.h"
#include "pip/context.h"

/* Raw API calls */

#define Pip_CreatePartition(a, b, c, d, e)  __Arch_APICall(CREATEPARTITION, 5, a, b, c, d, e)
#define Pip_CountToMap(a, b)                __Arch_APICall(COUNTTOMAP, 2, a, b)
#define Pip_Prepare(a, b, c)                __Arch_APICall(PREPARE, 3, a, b, c)
#define Pip_AddVAddr(a, b, c, d, e, f)      __Arch_APICall(ADDVADDR, 6, a, b, c, d, e, f)
#define Pip_Get_Int_State(a)                __Arch_APICall(GET_INT_STATE, 1, a)
#define Pip_Set_Int_State(a)                __Arch_APICall(SET_INT_STATE, 1, a)
#define Pip_RemoveVAddr(a, b)               __Arch_APICall(REMOVEVADDR, 2, a, b)
#define Pip_MappedInChild(a)                __Arch_APICall(MAPPEDINCHILD, 1, a)
#define Pip_DeletePartition(a)              __Arch_APICall(DELETEPARTITION, 1, a)
#define Pip_Collect(a, b)                   __Arch_APICall(COLLECT, 2, a, b)
#define Pip_Yield(a, b, c, d, e)            __Arch_APICall(YIELD, 5, a, b, c, d, e)

/* Wrappers */

/*!
 * \brief Map a page at the "source" address to the "destination" address in the "partition" partition
 * \param source Address of the page to map to the destination partition
 * \param partition Partition descriptor of the destination partition
 * \param destination Address where to map the page in the destination partition
 * \return 1 if the function succeed, 0 otherwise
 */
uint32_t Pip_MapPageWrapperFlags(uint32_t source, uint32_t partition, uint32_t destination, uint32_t flags);

/*!
 * \brief Print a character to the serial port
 * \param c The character to print to the serial port
 */
void Pip_Debug_Putc(char c);

/*!
 * TODO
 */
uint64_t time(uint64_t *t);

/*!
 * \brief Context structure allocator
 * \return A pointer to a newly allocated context structure
 */
user_ctx_t *Pip_AllocContext(void);

/*!
 * \deprecated Here for compatibility reasons. Use Pip_Yield() function instead
 * \brief Dispatch an interrupt to a child partition or to its parent
 * \param calleePartDescVAddr The callee partition descriptor virtual address
 * \param calleeVidtVAddr The callee VIDT virtual address
 * \param userTargetInterrupt The user target interrupt number
 */
void Pip_Notify(uint32_t calleePartDescVAddr, uint32_t calleeVidtVAddr, uint32_t userTargetInterrupt);

/*!
 * \deprecated Here for compatibility reasons. Use Pip_Yield() function instead
 * \brief Activate another partition and restore its execution context
 */
void Pip_Resume(void);

/*!
 * \brief Register a handler in the current VIDT
 * \param handlerContext A pointer to the context structure of the handler
 * \param interruptNumber The interrupt number to handle
 * \param handlerAddress The address of the handler
 * \param stackAddress The address of the stack
 * \param pipflags The PIP flags
 */
void Pip_RegisterInterrupt(user_ctx_t *handlerContext, uint32_t interruptNumber, uint32_t handlerAddress, uint32_t stackAddress, uint32_t pipFlags);

#endif /* __API__ */

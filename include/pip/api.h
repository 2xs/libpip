/*******************************************************************************/
/*  © Université Lille 1, The Pip Development Team (2015-2020)                 */
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

void Pip_Debug_Putc(char c);
uint32_t Pip_MapPageWrapper(uint32_t source, uint32_t partition, uint32_t destination);

#endif

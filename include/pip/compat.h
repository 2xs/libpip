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

#ifndef __LIBPIP_1_COMPAT__
#define __LIBPIP_1_COMPAT__

#include <stdint.h>

/* API Calls */
#define createPartition                     Pip_CreatePartition
#define countToMap                          Pip_CountToMap
#define prepare                             Pip_Prepare
#define mapPage                             Pip_AddVAddr
#define unmapPage                           Pip_RemoveVAddr
#define mappedInChild                       Pip_MappedInChild
#define deletePartition                     Pip_DeletePartition
#define getIntState                         Pip_Get_Int_State
#define setIntState                         Pip_Set_Int_State

/* Former x86 LibPip - this shouldn't be here, but we'll leave it here for compatibility issues */
#define outb                                Pip_Outb
#define inb                                 Pip_Inb
#define outw                                Pip_Outw
#define inw                                 Pip_Inw
#define outl                                Pip_Outl
#define inl                                 Pip_Inl
#define outaddr                             Pip_Outaddrl

/* Wrappers */
#define initPaging                          Pip_InitPaging
#define allocPage                           Pip_AllocPage
#define freePage                            Pip_FreePage
#define mapPageWrapper                      Pip_MapPageWrapper

/* Debug output */
#define puts                                Pip_Debug_Puts
#define putc                                Pip_Debug_Putc
#define puthex                              Pip_Debug_PutHex
#define putdec                              Pip_Debug_PutDec

/* Interrupt management */
#define registerInterrupt                   Pip_RegisterInterrupt
#define initVidt                            Pip_InitVIDT

#endif /* __LIBPIP_1_COMPAT__ */

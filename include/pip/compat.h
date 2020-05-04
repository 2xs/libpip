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
#endif

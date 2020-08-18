#include <stdint.h>

#include "pip/api.h"
#include "pip/vidt.h"
#include "pip/paging.h"
#include "pip/stdio.h"

/*!
 * \brief Context structure allocator
 * \return A pointer to a context structure
 */
extern user_ctx_t *Pip_AllocContext(void)
{
	static uint32_t availableBytes = sizeof(user_ctx_t);
	static uint32_t contextAddress = 0;

	availableBytes -= sizeof(user_ctx_t);

	if (availableBytes == 0)
	{
		contextAddress = (uint32_t) Pip_AllocPage();
		availableBytes = PAGE_SIZE;
	}
	else
	{
		contextAddress += sizeof(user_ctx_t);
	}

	return (user_ctx_t *) contextAddress;
}

/*!
 * \deprecated Here for compatibility reasons. Use Pip_Yield() function instead
 * \brief Dispatch an interrupt to a child partition or to its parent
 * \param calleePartDescVAddr The callee partition descriptor virtual address
 * \param calleeVidtVAddr The callee VIDT virtual address
 * \param userTargetInterrupt The user target interrupt number
 */
extern void Pip_Notify(uint32_t calleePartDescVAddr,
		       uint32_t calleeVidtVAddr,
		       uint32_t userTargetInterrupt)
{
	VIDT[1023] = (user_ctx_t *) calleePartDescVAddr;

	if (calleePartDescVAddr != 0)
	{
		((user_ctx_t **) calleeVidtVAddr)[1023] =  (user_ctx_t *) 0;
	}

	Pip_Yield(calleePartDescVAddr, userTargetInterrupt, 70, 0, 0);
}

/*!
 * \deprecated Here for compatibility reasons. Use Pip_Yield() function instead
 * \brief Activate another partition and restore its execution context
 */
extern void Pip_Resume(void)
{
	Pip_Yield((uint32_t) VIDT[1023], 70, 255, 0, 0);
}

/*!
 * \brief Register a handler in the current VIDT
 * \param handlerContext A pointer to the context structure of the handler
 * \param interruptNumber
 * \param  handlerAddress
 * \param stackAddress
 * \param pipflags
 */
extern void Pip_RegisterInterrupt(user_ctx_t *handlerContext,
				  uint32_t interruptNumber,
				  uint32_t handlerAddress,
				  uint32_t stackAddress,
				  uint32_t pipFlags)
{
	handlerContext->valid    = 0;
	handlerContext->eip      = handlerAddress;
	handlerContext->pipflags = pipFlags;
	handlerContext->eflags   = 0x2;
	handlerContext->regs.ebp = stackAddress + PAGE_SIZE;
	handlerContext->regs.esp = stackAddress + PAGE_SIZE;
	handlerContext->valid    = 1;

	VIDT[interruptNumber] = handlerContext;
}

#include <stdint.h>

#include <pip/vidt.h>
#include <pip/paging.h>

/*!
 * \brief Context structure allocator
 * \return A pointer to a context structure
 */
extern user_ctx_t *Pip_AllocContext(void)
{
	static uint32_t availableBytes = 0;
	static uint32_t contextAddress = 0;

	if (availableBytes == 0)
	{
		contextAddress = (uint32_t) Pip_AllocPage();
		availableBytes = PAGE_SIZE;
	}
	else
	{
		contextAddress += sizeof(user_ctx_t);
		availableBytes -= sizeof(user_ctx_t);
	}

	return (user_ctx_t *) contextAddress;
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
	// Fill the context structure with the handler data
	handlerContext->valid    = 0;
	handlerContext->eip      = handlerAddress;
	handlerContext->pipflags = pipFlags;
	handlerContext->eflags   = 0x202;
	handlerContext->regs.ebp = stackAddress + PAGE_SIZE;
	handlerContext->regs.esp = stackAddress + PAGE_SIZE;
	handlerContext->valid    = 1;

	// Save the context address in the VIDT
	VIDT[interruptNumber] = handlerContext;
}

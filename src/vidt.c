#include <stdint.h>
#include <pip/vidt.h>

/*!
 * \fn extern void Pip_RegisterInterrupt(user_ctx_t *handlerContext,
 *		uint32_t interruptNumber, uint32_t handlerAddress)
 * \brief Register a handler in the current VIDT
 * \param handlerContext A pointer to the context structure of the handler
 * \param interruptNumber
 * \param  handlerAddress
 * \param stackAddress
 * \param pipflags
 */
extern void Pip_RegisterInterrupt(user_ctx_t *handlerContext,
		uint32_t interruptNumber, uint32_t handlerAddress,
		uint32_t stackAddress, uint32_t pipFlags)
{
	// Fill the context with the handler address
	handlerContext->valid    = 0;
	handlerContext->eip      = handlerAddress;
	handlerContext->pipflags = pipFlags;
	handlerContext->eflags   = 0x202;
	handlerContext->regs.ebp = stackAddress;
	handlerContext->regs.esp = stackAddress;
	handlerContext->valid    = 1;

	// Save the context address in the VIDT
	VIDT[interruptNumber] = handlerContext;
}

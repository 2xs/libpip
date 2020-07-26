#include <stdint.h>

#include <pip/stdio.h>
#include <pip/vidt.h>

/*!
 * \fn extern void Pip_RegisterInterrupt(user_ctx_t *handlerContext,
 *		uint32_t interruptNumber, uint32_t handlerAddress)
 * \brief Register a han
 *
 */
extern void Pip_RegisterInterrupt(user_ctx_t *handlerContext,
		uint32_t interruptNumber, uint32_t handlerAddress)
{
	// Initialize the context with zero
	memset(handlerContext, 0, sizeof(user_ctx_t));

	// Fill the context with the handler address
	handlerContext->eip   = handlerAddress;
	handlerContext->valid = 1;

	// Save the context address in the VIDT
	VIDT[interruptNumber] = handlerContext;
}

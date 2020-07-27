#ifndef __VIDT__
#define __VIDT__

#include <stdint.h>

/*!
 * \def VIDT_ADDR
 * \brief The VIDT address
 */
#define VIDT_VADDR	0xfffff000

/*!
 * \def PAGE_SIZE
 * \brief The page size
 */
#define PAGE_SIZE	4096

/*!
 * \def VIDT
 * \brief The VIDT of the current partition
 */
#define VIDT	((user_ctx_t **) VIDT_VADDR)


/*!
 * \def__packed
 */
#define __packed __attribute__((packed))

/*!
 * \struct pushad_regs_t
 * \brief Registers structure for x86
 */
typedef struct __packed pushad_regs_s
{
	uint32_t edi; //!< General register EDI
	uint32_t esi; //!< General register ESI
	uint32_t ebp; //!< Base pointer
	uint32_t esp; //!< Stack pointer
	uint32_t ebx; //!< General register EBX
	uint32_t edx; //!< General register EDX
	uint32_t ecx; //!< General register ECX
	uint32_t eax; //!< General register EAX
} pushad_regs_t;

/*!
 * \struct user_ctx_t
 * \brief User saved context
 */
typedef struct __packed user_ctx_s
{
	uint32_t eip;       //!< Extended instruction pointer
	uint32_t pipflags;  //!< Flags used by PIP
	uint32_t eflags;    //!< Status register
	pushad_regs_t regs; //!< General-purpose registers
	uint32_t valid;     //!< Structure validity: 1 valid, 0 invalid
	uint32_t nfu[4];    //!< Unused
} user_ctx_t;

/*!
 * \def INTERRUPT_HANDLER(handler)
 * \brief
 */
#define INTERRUPT_HANDLER(handlerName)				\
	user_ctx_t handlerName##Context; void handlerName(void)

/*!
 * \def INTERRUPT_REGISTER(interruptNumber, handlerAddress, stackAddress, pipFlags)
 * \brief
 */
#define INTERRUPT_REGISTER(interruptNumber, handlerName, stackAddress, pipFlags)	\
	Pip_RegisterInterrupt(&handlerName##Context, interruptNumber,			\
		(uint32_t) (handlerName), (uint32_t) (stackAddress), pipFlags)

extern user_ctx_t *Pip_AllocContext(void);

extern void Pip_RegisterInterrupt(user_ctx_t *handlerContext,
				  uint32_t interruptNumber,
				  uint32_t handlerAddress,
				  uint32_t stackAddress,
				  uint32_t pipFlags);

#endif

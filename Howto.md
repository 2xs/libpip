# HowTo

## Compatibility

Since latest LibPip, the interface with the library has slightly changed. That being said, you can add `#include "pip/compat.h"` to fix most of these issues without having to change anything else to the partition's code.

## IO-ports

LibPip embeds virtual IO-ports accesses, in the "pip/arch_api.h" C header. You need to include two LibPip include directories in your project :
* `include`, which contains the architecture-independant API calls,
* `arch/x86/include`, which contains the architecture-dependant API calls.

It defines right now the "inb" and "outb" methods and their derivatives, taking common IO-port related arguments, such as the port and value.

## VIDT and interrupts

LibPip embeds Virtual IDT related methods, in the "vidt.h" header.

This header can be included in assembly (.S) and C (.c) source files.

In C sources, this header exports interrupt registering methods, as well as INTERRUPT_HANDLER(asm_hdlr, c_hdlr) and END_OF_INTERRUPT macros.

An interrupt handler is then defined as such :

* int.S:

    INTERRUPT_HANDLER(asm_timer, c_timer)

* int.c:

    INTERRUPT_HANDLER(asm_timer, c_timer)
    /* Do some stuff here */
    END_OF_INTERRUPT
    Pip_RegisterInterrupt(33, &asm_timer, (uint32_t*)timer_int_stack);

## Porting LibPip to another architecture

First, you need to create a sub-directory in `arch` corresponding to your architecture.

Then, you need to port only two methods :
* `__Arch_APICall`, which takes an API call number, a number of arguments and then an undefined amount of parameters (see the x86 implementation for reference).
* `Pip_Debug_Putc`, which prints a character on an output device (usually a serial link). If a serial output is not required, feel free to stub this method.

## About variants

LibPip now support variants, i.e. different implementations of the same hardware architecture.
You can add your own variant in `arch/target/variants` and pass it to the `make` command (e.g. `make ARCH=x86 VARIANT=galileo`) to compile LibPip using these files.
By default, the `default` variant is compiled. On the x86 architecture, it only contains the `Pip_Debug_Putc` method.

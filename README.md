# LibPip is a library to embed Pepin-related operations.

# HowTo : IO-ports

LibPip embeds virtual IO-ports accesses, in the "io.h" C header.

It defines right now the "inb" and "outb" methods, taking common IO-port related arguments, such as the port and value.

# HowTo : VIDT and interrupts

LibPip embeds Virtual IDT related methods, in the "vidt.h" header.

This header can be included in assembly (.S) and C (.c) source files.

In C sources, this header exports interrupt registering methods, as well as INTERRUPT_HANDLER(asm_hdlr, c_hdlr) and END_OF_INTERRUPT macros.

An interrupt handler is then defined as such :

* int.S:
    * INTERRUPT_HANDLER(asm_timer, c_timer)
* int.c:
    * INTERRUPT_HANDLER(asm_timer, c_timer)
    * /* Do some stuff here */
    * END_OF_INTERRUPT
    * registerInterrupt(33, &asm_timer, (uint32_t*)timer_int_stack);

# Contributors

* Quentin Bergougnoux
* Etienne Helluy-Lafont

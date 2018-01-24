# LibPip - x86 Default

This x86 variant builds for the x86_multiboot target of the Pip proto-kernel.

It uses far calls (callgates) as a way to request kernel services.

It doesn't implement the Pip_SmpRequest() service yet.

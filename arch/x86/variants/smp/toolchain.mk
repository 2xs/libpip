# Toolchain

CC=i386-elf-gcc
LD=i386-elf-ld
AS=nasm
AR=i386-elf-ar

# C flags
CFLAGS=-c -ffreestanding -nostdlib -Wall -Werror -Wextra -fno-builtin -Wno-unused-parameter -Wno-unused-variable -m32 -O2 -fno-caller-saves
CFLAGS+=$(foreach dir, $(INCDIR), -I$(dir))

# Assembler flags
ASFLAGS=-felf

# Archiver flags
ARFLAGS=rcs

# Toolchain

CC=gcc
LD=ld
AS=nasm
AR=ar

# C flags
CFLAGS=-c -ffreestanding -nostdlib -Wall -Werror -Wextra -fno-builtin -Wno-unused-parameter -Wno-unused-variable -m32 -O2 -fno-caller-saves
CFLAGS+=$(foreach dir, $(INCDIR), -I$(dir))

# Assembler flags
ASFLAGS=-felf

# Archiver flags
ARFLAGS=rcs

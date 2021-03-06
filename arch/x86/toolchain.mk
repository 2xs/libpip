# Toolchain

CC=gcc
LD=ld
AS=gcc
AR=ar

# C flags
CFLAGS=-c -ffreestanding -nostdlib -Wall -Werror -Wextra -fno-builtin -Wno-unused-parameter -Wno-unused-variable -m32 -fno-caller-saves -fno-stack-protector -fno-pic -no-pie
CFLAGS+=$(foreach dir, $(INCDIR), -I$(dir))

# Assembler flags
ASFLAGS=-m32 -c -I. -I./include -fomit-frame-pointer --freestanding -nostdlib -fno-stack-protector

# Archiver flags
ARFLAGS=rcs

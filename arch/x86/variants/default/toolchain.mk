# Toolchain

CC=i386-elf-gcc
LD=i386-elf-ld
AS=i386-elf-gcc
AR=i386-elf-ar

# C flags
CFLAGS=-c -ffreestanding -nostdlib -Wall -Werror -Wextra -fno-builtin -Wno-unused-parameter -Wno-unused-variable -m32 -fno-caller-saves -fno-stack-protector -fno-pic -no-pie -O2
CFLAGS+=$(foreach dir, $(INCDIR), -I$(dir))

# Assembler flags
ASFLAGS=-m32 -c -I. -I./include -fomit-frame-pointer --freestanding -nostdlib -fno-stack-protector -fno-pic -no-pie

# Archiver flags
ARFLAGS=rcs

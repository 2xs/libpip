UNAME_S=$(shell uname -s)

# Use /usr/bin packages in Linux, MacPorts in Darwin
ifeq ($(UNAME_S),Linux)
CC=gcc
AR=ar
AS=gcc
endif
ifeq ($(UNAME_S),Darwin)
CC=/opt/local/bin/i386-elf-gcc
AR=/opt/local/bin/i386-elf-ar
AS=/opt/local/bin/i386-elf-gcc
endif
ifeq ($(UNAME_S),FreeBSD)
CC=gcc
AR=ar
AS=gcc
endif

# Directories
SRCDIR=src
INCDIR=include

# Generate source and object list
SOURCES=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SOURCES:.c=.o)
ASOURCES=$(wildcard $(SRCDIR)/*.S)
AOBJ=$(ASOURCES:.S=.o)

# C compiler flags
CFLAGS=-c -ffreestanding -nostdlib -Wall -Werror -Wextra -fno-builtin -Wno-unused-parameter -Wno-unused-variable -m32 -O2 -fno-caller-saves
CFLAGS+=-I$(INCDIR)

ASFLAGS=-m32 -c -I. -I./include -fomit-frame-pointer --freestanding -nostdlib -fno-stack-protector

# Archiver flags
ARFLAGS=rcs

# Lib directory and output file
LIBDIR=lib
LIB=$(LIBDIR)/libpip.a

.PHONY: all

all: $(LIBDIR) $(LIB)

clean: 
	rm -rf $(LIBDIR) $(OBJ) $(AOBJ)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(LIB): $(OBJ) $(AOBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

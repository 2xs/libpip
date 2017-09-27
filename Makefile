# Architecture
ARCH=x86
VARIANT=default

# Directories
SRCDIR=src arch/$(ARCH)/ arch/$(ARCH)/variants/$(VARIANT)/
INCDIR=include arch/$(ARCH)/include/ arch/$(ARCH)/variants/$(VARIANT)/include/

# Generate source and object list
SOURCES=$(foreach dir, ${SRCDIR}, $(wildcard $(dir)/*.c))
OBJ=$(SOURCES:.c=.o)
ASOURCES=$(foreach dir, ${SRCDIR}, $(wildcard $(dir)/*.S))
AOBJ=$(ASOURCES:.S=.o)

# Lib directory and output file
LIBDIR=lib
LIB=$(LIBDIR)/libpip.a

include arch/$(ARCH)/toolchain.mk

# Add define for variant and architecture
ARCHDEF=$(shell echo $(ARCH) | tr a-z A-Z)
VARIANTDEF=$(shell echo $(VARIANT) | tr a-z A-Z)
CFLAGS+=-DARCH_$(ARCHDEF)
CFLAGS+=-DVARIANT_$(VARIANTDEF)

.PHONY: info all

all: info $(LIBDIR) $(LIB)

info:
	@echo Building LibPip2 for architecture $(ARCH), variant $(VARIANT).

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

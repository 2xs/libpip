###############################################################################
#  © Université de Lille, The Pip Development Team (2015-2021)                #
#                                                                             #
#  This software is a computer program whose purpose is to run a minimal,     #
#  hypervisor relying on proven properties such as memory isolation.          #
#                                                                             #
#  This software is governed by the CeCILL license under French law and       #
#  abiding by the rules of distribution of free software.  You can  use,      #
#  modify and/ or redistribute the software under the terms of the CeCILL     #
#  license as circulated by CEA, CNRS and INRIA at the following URL          #
#  "http://www.cecill.info".                                                  #
#                                                                             #
#  As a counterpart to the access to the source code and  rights to copy,     #
#  modify and redistribute granted by the license, users are provided only    #
#  with a limited warranty  and the software's author,  the holder of the     #
#  economic rights,  and the successive licensors  have only  limited         #
#  liability.                                                                 #
#                                                                             #
#  In this respect, the user's attention is drawn to the risks associated     #
#  with loading,  using,  modifying and/or developing or reproducing the      #
#  software by the user in light of its specific status of free software,     #
#  that may mean  that it is complicated to manipulate,  and  that  also      #
#  therefore means  that it is reserved for developers  and  experienced      #
#  professionals having in-depth computer knowledge. Users are therefore      #
#  encouraged to load and test the software's suitability as regards their    #
#  requirements in conditions enabling the security of their systems and/or   #
#  data to be ensured and,  more generally, to use and operate it in the      #
#  same conditions as regards security.                                       #
#                                                                             #
#  The fact that you are presently reading this means that you have had       #
#  knowledge of the CeCILL license and that you accept its terms.             #
###############################################################################

# Architecture
ARCH        = x86
VARIANT     = default

# Directories
SRCDIR      = src
SRCDIR     += arch/$(ARCH)
SRCDIR     += arch/$(ARCH)/variants/$(VARIANT)

INCDIR      = include
INCDIR     += arch/$(ARCH)/include
INCDIR     += arch/$(ARCH)/variants/$(VARIANT)/include

# Generate source and object list
SOURCES     = $(foreach dir, ${SRCDIR}, $(wildcard $(dir)/*.c))
OBJ         = $(SOURCES:.c=.o)

ASOURCES    = $(foreach dir, ${SRCDIR}, $(wildcard $(dir)/*.S))
AOBJ        = $(ASOURCES:.S=.o)

# Lib directory and output file
LIBDIR      = lib
LIB         = $(LIBDIR)/libpip.a

# Documentation directory
DOCDIR      = doc

include arch/$(ARCH)/variants/$(VARIANT)/toolchain.mk

# Add define for variant and architecture
ARCHDEF     = $(shell echo $(ARCH) | tr a-z A-Z)
VARIANTDEF  = $(shell echo $(VARIANT) | tr a-z A-Z)

CFLAGS     += -DARCH_$(ARCHDEF)
CFLAGS     += -DVARIANT_$(VARIANTDEF)

.PHONY: info all doc

all: info $(LIBDIR) $(LIB)

info:
	@echo Building LibPip2 for architecture $(ARCH), variant $(VARIANT).

clean:
	rm -rf $(LIBDIR) $(DOCDIR) $(OBJ) $(AOBJ)

$(LIBDIR):
	mkdir -p $(LIBDIR)

doc:
	mkdir -p $(DOCDIR)
	doxygen

$(LIB): $(OBJ) $(AOBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

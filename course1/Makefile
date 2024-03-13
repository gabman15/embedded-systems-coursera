#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for Embedded Systems Course Projects
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      compile-all: Compiles all source files
#      all: Builds Target executable
#      build: Builds Target executable
#      clean: Clears build directory
#      %.i, %.asm, %.o
#      
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------


# Platform Overrides
PLATFORM = MSP432
GCCVER = OLD

ifdef VERBOSE
	VERBOSITY = -DVERBOSE
endif
ifdef COURSE1
	COURSESEL = -DCOURSE1
endif

include sources.mk

TARGET = course1

SRCDIR = ./src
BUILDDIR = ./build

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
ifeq ($(PLATFORM), MSP432)
	CPU = cortex-m4
	ARMARCH = thumb
	ARCH = armv7e-m
	FLOAT = hard
	FPU = fpv4-sp-d16
	SPECS = nosys.specs
	PLATCFLAGS = -mcpu=$(CPU) -m$(ARMARCH) -mfpu=$(FPU) --specs=$(SPECS) \
				 -mfloat-abi=$(FLOAT) -march=$(ARCH)
endif

# Compiler Tools
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
else
	CC = gcc
	LD = ld
	OBJDUMP = objdump
	SIZE = size
endif

# Compiler Flags
ifeq ($(GCCVER), OLD)
	CFLAGS = $(PLATCFLAGS) -Wall -Werror -g -O0 -std=c99
else
	CFLAGS = $(PLATCFLAGS) -Wall -g -O0 -std=c99
endif

CPPFLAGS = -D$(PLATFORM) $(VERBOSITY) $(COURSESEL) $(addprefix -I,$(INCLUDES)) -MMD -MP

ifeq ($(PLATFORM), MSP432)
	LDFLAGS = -Wl,-T $(LINKER_FILE) -Wl,-Map=$(BUILDDIR)/$(TARGET).map
else
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif

#SRCS = $(addprefix $(SRCDIR)/,$(SOURCES))
OBJS = $(SOURCES:%.c=$(BUILDDIR)/%.o)
DEPS = $(OBJS:.o=.d)

.PHONY: test
test:
	echo $(DEPS)

$(BUILDDIR)/%.i : $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) -E $< $(CPPFLAGS) -o $@

$(BUILDDIR)/%.asm : $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

$(BUILDDIR)/$(TARGET).asm : $(TARGET).out
	mkdir -p $(dir $@)
	$(OBJDUMP) -d $< > $@

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

$(BUILDDIR)/$(TARGET).out : $(OBJS)
	mkdir -p $(dir $@)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(BUILDDIR)/$(TARGET).out
	$(SIZE) $(BUILDDIR)/$<

.PHONY: clean
clean:
	rm -r $(BUILDDIR)

-include $(DEPS)

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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------


# Platform Overrides
PLATFORM = MSP432
GCCVER = OLD

include sources.mk

TARGET = c1m2

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
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

CPPFLAGS = -D$(PLATFORM) $(addprefix -I,$(INCLUDES)) -MMD -MP

ifeq ($(PLATFORM), MSP432)
	LDFLAGS = -Wl,-T $(LINKER_FILE) -Wl,-Map=$(TARGET).map
else
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(OBJS:.o=.d)

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $< > $@

# %.o : %.c
# 	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

$(TARGET).out : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out
	$(SIZE) $<

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.i *.asm *.d

-include $(DEPS)

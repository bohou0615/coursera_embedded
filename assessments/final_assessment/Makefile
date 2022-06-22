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
include sources.mk

TARGET = course1

PLATFORM = HOST

GEN_FLAGS = \
			-Wall \
			-Werror \
			-g \
			-O0 \
			-std=c99
			
INCLUDES = -I include/common/

LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m

TEST = NO


#HOST
ifeq ($(PLATFORM),HOST) 
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	LD = ld
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
#msp432
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LDFLAGS = -Wl,-Map=$(TARGET).map -L ../ $(LINKER_FILE)
	CFLAGS = 	$(GEN_FLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)
	OBJDUMP = arm-none-eabi-objdump

endif

#test flag
ifeq ($(TEST), YES)
	TESTFLAGS = -D COURSE1 -D VERBOSE
else
	TESTFLAGS = -D COURSE1
endif

OBJS = $(SOURCES:.c=.o)
PREPS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)


%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@

.PHONY: compile-all 
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out 

$(TARGET).out: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@
	$(SIZE) $@

.PHONY: all_files
all_files: $(SOURCES)
	make $(PREP)
	make $(ASMS)
	make compile-all
	make $(TARGET).out
	$(OBJDUMP) -t $(TARGET).out > $(TARGET).symbol_table

.PHONY: clean
clean:
		rm -f *.o *.i *.asm  $(TARGET).out*  $(TARGET).map


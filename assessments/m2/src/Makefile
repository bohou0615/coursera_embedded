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

TARGET = c1m2

PLATFORM = HOST

GEN_FLAGS = \
			-Wall \
			-Werror \
			-g \
			-O0 \
			-std=c99

#HOST
ifeq ($(PLATFORM),HOST) 

	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size
#msp432
else
	CPU = cortex-m4
	ARCH = armv7e-m
	SOURCES+= 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	INCLUDES+= 	-I ../include/CMSIS/ \
				-I ../include/msp432/
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)


	CFLAGS = 	$(GEN_FLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)

endif



OBJS = $(SOURCES:.c=.o)
PREPS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)


%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out 

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
		rm -f *.out *.map *.o *.asm *.i
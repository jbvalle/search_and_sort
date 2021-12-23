#Binary Building tool

#declare Phony in Phony so incase a file has the same name
#the phony will still be run
.Phony = all clean

#declare all variables
CC = gcc
#object dir
ODIR=obj

#header dir
IDIR=../includes/

#declare Sources and Binaries
SRCS := $(wildcard *.c)

#_OBJF := $(SRCS:%.c=%.o)
_OBJF := $(SRCS:%.c=%.o)
OBJF  := $(patsubst %,$(ODIR)/%,$(_OBJF))

_HEADERS := str2args.h
HEADERS := $(patsubst %,$(IDIR)/%,$(_HEADERS))

BINS := $(SRCS:%.c=%)
TARGET := main

#declare all Compilation and Linkerflags
CFLAGS = -g -Wall -Wextra -pedantic -I$(IDIR)
LFLAGS= -lm

#define the "all" target
all: clean SHOW_README $(OBJF) $(TARGET) 

#target <- objectfiles
$(TARGET): $(OBJF)
	@$(CC) -o $@ $^ $(LFLAGS) $(CFLAGS)

$(ODIR)/%.o: %.c
	@$(CC) -c -o $@ $^ $(CFLAGS)

#README
SHOW_README:
	@cat ../README.txt
#clean target
clean:
	@echo Cleaning Up
	@rm -rvf $(ODIR)/*.o *.exe ${BINS}



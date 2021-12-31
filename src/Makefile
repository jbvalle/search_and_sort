#Binary Building tool

#declare Phony in Phony so incase a file has the same name
#the phony will still be run

#mark-up-var
COLOR=\e[1;93m
RESET=\e[0m

.Phony = all clean

#declare all variables
CC = gcc
#object dir
ODIR=obj

#header dir
IDIR=../includes/

#declare Sources and Binaries
SRCS := $(wildcard *.c)

_OBJF := $(SRCS:%.c=%.o)
OBJF  := $(patsubst %,$(ODIR)/%,$(_OBJF))

_HEADERS := $(SRCS:%.c=%.h)
HEADERS := $(patsubst %,$(IDIR)/%,$(_HEADERS))

BINS := $(SRCS:%.c=%)

TARGET := main

#declare all Compilation and Linkerflags:
CFLAGS = -g -Wall -Wextra -pedantic -I$(IDIR) -std=c99

#libraries
LFLAGS= -lm

#define the "all" target
all: clean SHOW_README $(OBJF) $(TARGET) RUN

#target <- objectfiles
$(TARGET): $(OBJF)
	@$(CC) $(CFLAGS) -DERR_FLAG=0 -o $@ $^ $(LFLAGS)

$(ODIR)/%.o: %.c | obj
	@$(CC) -DERR_FLAG=0 -c -o $@ $^ $(CFLAGS) 

#README
SHOW_README:
	@echo "$(COLOR)"
	@cat ../README.txt
	@echo "$(RESET)"

RUN:
	@./main

obj:
	@mkdir -p $@

# --leak-check=full: "each individual leak will be shown in detail"
# --show-leak-kinds=all: Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
# --track-origins=yes: Favor useful output over speed. This tracks the origins of uninitialized values
# --verbose: Can tell you about unusual behavior of your program. Repeat for more verbosity.
memleak: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $^

#clean target
clean:
	@echo Cleaning Up
	@rm -rvf $(ODIR)/*.o *.exe $(BINS) $(ODIR)

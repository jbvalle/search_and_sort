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
all: clean $(OBJF) $(TARGET) RUN

#target <- objectfiles
$(TARGET): $(OBJF)
	@$(CC) $(CFLAGS) -DERRFLAG=0 -Dmemleak=1 -o $@ $^ $(LFLAGS)

$(ODIR)/%.o: %.c | obj
	@$(CC) -DERRFLAG=0 -Dmemleak=0 -c -o $@ $^ $(CFLAGS) 

#README
SHOW_README:
	@echo "$(COLOR)"
	@cat ../README.md
	@echo "$(RESET)"

RUN: 
	@./$(TARGET)

obj:
	@mkdir -p $@

# --leak-check=full: "each individual leak will be shown in detail"
# --track-origins=yes: Favor useful output over speed. This tracks the origins of uninitialized values
# --verbose: Can tell you about unusual behavior of your program. Repeat for more verbosity.
memleak_check: $(SRCS)
	$(CC) $(CFLAGS) -Dmemleak=0 -o $(TARGET) $^ $(LFLAGS)
	valgrind --leak-check=full  --tool=memcheck --track-origins=yes ./$(TARGET)

#Setting ERRFLAG
errsort: $(SRCS)
	$(CC) $(CFLAGS) -DERRFLAG=1 -o $(TARGET) $^ $(LFLAGS)
	./$(TARGET)
	
testing: $(SRCS)
	$(CC) $(CFLAGS) -Dmemleak=1 -o $(TARGET) $^ $(LFLAGS)
	./$(TARGET)

debug: $(SRCS)
	ulimit -c unlimited
	$(CC) $(CFLAGS) -Dmemleak=0 -o $(TARGET) $^ $(LFLAGS)
	gdb ./$(TARGET) core

#clean target
clean:
	@echo Cleaning Up
	@rm -rvf $(ODIR)/*.o *.exe $(BINS) $(ODIR) .*swo .*swp

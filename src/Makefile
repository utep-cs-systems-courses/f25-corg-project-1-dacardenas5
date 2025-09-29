
#object files

OBJS = uiMain.o tokenizer.o history.o

#compiler flags

CFLAGS = -g -O3

# Default target

all: tokenizer

#build executable

tokenizer: $(OBJS)
	cc $(CFLAGS) -o tokenizer $(OBJS)

uiMain.o: tokenizer.h history.h
tokenizer.o: tokenizer.h
history.o: tokenizer.h history.h

#clean files
clean:
	rm -f *.o tokenizer *~ \#*#

#run
run: tokenizer
	./tokenizer

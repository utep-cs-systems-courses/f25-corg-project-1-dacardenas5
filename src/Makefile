
#object files

OBJS = uiMain.o

#compiler flags

CFLAGS = -g -O3

# Default target

all: tokenizer

#build executable

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

#shared header
# $(OBJS): sharedHeader.h

#clean files
clean:
	rm -f *.o tokenizer *~ \#*#

#run
run: tokenizer
	./tokenizer

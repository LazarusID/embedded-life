.PHONY: clean all

CHECK_FLAGS=`pkg-config --cflags check`
CHECK_LIBS=`pkg-config --libs check`

CFLAGS=-I../mock -I../src $(CHECK_FLAGS)
LDFLAGS=$(CHECK_LIBS)
VPATH=../mock:../src

SRCS=$(wildcard *.c)
BASES=$(basename $(SRCS))
OBJS=$(addsuffix .o, $(BASES))

# Include files with functions to test here (use .o extension)
SUT=

all: test_suite
	./test_suite

test_suite: $(OBJS) $(SUT)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f *.o
	rm -f test_suite
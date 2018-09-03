.PHONY: clean

SRCS=$(wildcard *.c)
BASES=$(basename $(SRCS))
OBJS=$(addsuffix .o, $(BASES))

libmock.a: $(OBJS)
	ar -rs $^ $@

clean:
	rm -f *.o
	rm -f *.a
SRCS=$(wildcard *.c)
BASES=$(basename $(SRCS))
OBJS=$(addsuffix .o, $(BASES))

CFLAGS=-I$(RGBINCLUDEPATH)
LIBS=-L$(RGBLIBPATH) -lrgbmatrix

life: $(OBJS)
	$(CC) $^ -o $@
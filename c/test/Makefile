CFLAGS = `pkg-config --cflags check` -I$(RGBINCLUDEPATH) -I../life
LIBS = `pkg-config --libs check`
VPATH=../life

SRCS=$(wildcard *.c)
BASES=$(basename $(SRCS))
OBJS=$(addsuffix .o, $(BASES))

SUT=rules.o board.o game.o

check: life-test
	./life-test

life-test: $(OBJS) $(SUT)
	$(CC) -o $@ $(OBJS) $(SUT) $(LIBS)
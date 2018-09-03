SRCS=$(wildcard *.c)
BASES=$(basename $(SRCS) $(CPPSRCS))
OBJS=$(addsuffix .o, $(BASES))

life: $(OBJS)
	$(CC) $^ $@ $(LDFLAGS)
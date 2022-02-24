HEADERS = stack.h ops.h parser.h
CFLAGS = -g
LDFLAGS = -lm

rpn-calc: main.o stack.o ops.o parser.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) *.o rpn-calc

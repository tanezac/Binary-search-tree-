C = gcc
CC = gcc
CFLAGS =-g -Wall -Wshadow
DEPS = buildTree.h traversals.h node.h buildTree.c traversals.c p0.c
OBJ = buildTree.o traversals.o p0.o
LDFLAGS = -static

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
p0: $(OBJ)
	$(CC)  $(CFLAGS) -o $@ $^

.PHONY: all clean
clean:
	/bin/rm -f $(OUTPUT) *.o *.log


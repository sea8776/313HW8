# Makefile for C99 Matrix Library + driver.c

CC      = gcc
CFLAGS  = -std=c99 -Wall -Wextra

# Link executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) matrixC.o driver.o -o driver

# Compile library implementation
matrixC.o: matrixC.c matrixC.h
	$(CC) $(CFLAGS) -c matrixC.c

# Compile test driver
driver.o: driver.c matrixC.h
	$(CC) $(CFLAGS) -c driver.c

# clean
clean:
	rm -f matrixC.o driver.o driver

# run driver
run:
	./driver

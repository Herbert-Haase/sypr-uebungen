# Makefile
CC=gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11 -pedantic

# Compile all C source files into individual executables
all: $(patsubst %.c, %, $(wildcard *.c))

# Rule to create the executable from the object file
%: %.o
	$(CC) $(CFLAGS) -o $@ $^

# Rule to create the object file from the C source file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up the compiled files
clean:
	rm -f $(patsubst %.c, %, $(wildcard *.c)) *.o

CC = gcc
CFLAGS = -Wall -Wextra -g

src = $(wildcard *.c)

.PHONY: all clean

all: shell

shell:
	$(CC) $(src) -o shell

clean:
	$(RM) -f shell
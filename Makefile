CC = gcc
CFLAGS = -Wall -Werror

SOURCES = main.c parser.c cmds_mngr.c
OBJECTS = $(SOURCES:.c=.o)

all: hw1shell

hw1shell: $(OBJECTS)
	$(CC) $(CFLAGS) -o hw1shell $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f *.o hw1shell
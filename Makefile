CC = gcc
CFLAGS = -Wall -Werror

SOURCES = main.c functions.c
OBJECTS = $(SOURCES:.c=.o)

all: hw1shell

hw1shell: $(OBJECTS)
    $(CC) $(CFLAGS) -o hw1shell $(OBJECTS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f *.o hw1shell5
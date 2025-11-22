C = gcc
CFLAGS = -g -Wall

SOURCES = $(.wildcard *.c)

TARGETS = $(SOURCES:.c=)

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

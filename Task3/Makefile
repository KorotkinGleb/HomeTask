CC = gcc
CFLAGS = -g -Wall
SRCMODULES = wordlist.c Lgraph.c
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

main: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

-include deps.mk

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

clean:
	rm -f *.o main deps.mk

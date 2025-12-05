CC=gcc
CFLAGS=-O3 -Wall -Iinclude

SRC=src/rtrie.o src/consensus.o src/rift_repl.o main.o

mmukocycle: $(SRC)
	$(CC) -o mmukocycle $(SRC)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f mmukocycle src/*.o *.o

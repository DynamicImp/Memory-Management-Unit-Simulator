CC = gcc
CFLAGS = -Wall -g

SRC = src/mmu.c
MAIN_SRC = $(SRC) src/main.c
TEST_SRC = $(SRC) tests/test_mmu.c
OBJ = $(SRC:.c=.o)

all: mmu test

mmu: $(MAIN_SRC:.c=.o)
	$(CC) $(CFLAGS) -o mmu $^

test: $(TEST_SRC:.c=.o)
	$(CC) $(CFLAGS) -o test $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f mmu test $(OBJ) src/*.o tests/*.o

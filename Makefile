CC = gcc
CFLAGS = -Wall -g

SRC = src/mmu.c src/main.c
TEST_SRC = tests/test_mmu.c
OBJ = $(SRC:.c=.o)

all: mmu test

mmu: $(OBJ)
	$(CC) $(CFLAGS) -o mmu $(OBJ)

test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o test $(SRC) $(TEST_SRC)

clean:
	rm -f mmu test $(OBJ)
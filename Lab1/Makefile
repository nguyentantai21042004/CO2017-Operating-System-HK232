CFLAGS = -Wall -Wextra
CC = gcc
VPATH = src:build

all: build/bin/calc

build/bin/calc: build/calc.o build/inputSolving.o build/ans.o build/error.o build/logic.o
	mkdir -p build/bin
	$(CC) $(CFLAGS) $^ -o $@

build/calc.o: calc.c
	mkdir -p build
	touch ans.txt
	$(CC) $(CFLAGS) -c $< -o $@

build/inputsolving.o: inputsolving.c
	$(CC) $(CFLAGS) -c $< -o $@

build/ans.o: ans.c
	$(CC) $(CFLAGS) -c $< -o $@

build/error.o: error.c
	$(CC) $(CFLAGS) -c $< -o $@

build/logic.o: logic.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rvf build

.PHONY: run
run: build/bin/calc
	./build/bin/calc

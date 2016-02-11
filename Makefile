CC=g++

all: main

main: MainSolution/MainSolution/Main.cpp
	$(CC) -o $@ $<

clean:
	$(rm) -rf main

.PHONY: clean all

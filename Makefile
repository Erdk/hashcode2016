CC=g++

all: main

main: MainSolution/MainSolution/Main.cpp
	$(CC) -o $@ $<

clean:
	rm main

.PHONY: clean all

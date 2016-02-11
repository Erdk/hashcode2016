CXX=g++
CXXFLAGS=-std=c++11 -g3 -ggdb
all: main

main: MainSolution/MainSolution/Main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm main

.PHONY: clean all

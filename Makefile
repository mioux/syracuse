CC=g++
CFLAGS = -g -Wall -lgmp -lstdc++
TARGETS = syracuse

output: main.cc
	gcc $< $(CFLAGS) -o $(TARGETS)

clean:
	rm $(TARGETS)
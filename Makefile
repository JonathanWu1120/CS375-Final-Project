CFLAGS=-Wall -Wextra -DDEBUG -pedantic -std=c++14
HEADERS=Node.h Edge.h AMGraph.h ALGraph.h

all:

testGraph: graphTester
	./graphTest

graphTester: graphTest.o
	g++ $(CFLAGS) -g graphTest.o -o graphTest
	
graphTest.o: graphTest.cpp $(HEADERS)
	g++ $(CFLAGS) -c graphTest.cpp
	
clean:
	rm *.o

gedit:
	gedit *.h *.cpp Makefile &

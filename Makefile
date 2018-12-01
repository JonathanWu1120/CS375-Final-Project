CFLAGS=-Wall -Wextra -DDEBUG -pedantic -std=c++14
HEADERS=Node.h Edge.h AMGraph.h ALGraph.h Kurskal.h

all:

test: graphTester
	./graphTest

graphTester: graphTest.o
	g++ $(CFLAGS) -g $^ -o graphTest

%.o: %.cpp $(HEADERS)
	g++ -c $(CFLAGS) $^
	
#graphTest.o: graphTest.cpp $(HEADERS)
#	g++ $(CFLAGS) -c graphTest.cpp
	
#Kurskal.o: Kurskal.cpp
#	g++ $(CFLAGS) -c Kurskal.cpp

clean:
	rm -f *.o *.gch graphTest

gedit:
	gedit *.h *.cpp Makefile &

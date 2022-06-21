COMP = g++

FLAGS = -Wall -std=c++11

all: runme1 runme2 runme3 runme4

clean:
	rm *.exe *.o

runme2: program20-2.o
	$(COMP) $(FLAGS) -o runme2 program20-2.o

runme1: program20-1.o
	$(COMP) $(FLAGS) -o runme1 program20-1.o

program20-1.o: program20-1.cpp
	$(COMP) $(FLAGS) -c program20-1.cpp

program20-2.o: program20-2.cpp
	$(COMP) $(FLAGS) -c program20-2.cpp

runme3: program20-3.o
	$(COMP) $(FLAGS) -o runme3 program20-3.o

program20-3.o: program20-3.cpp
	$(COMP) $(FLAGS) -c program20-3.cpp

runme4: program20-4.o
	$(COMP) $(FLAGS) -o runme4 program20-4.o

program20-4.o: program20-4.cpp
	$(COMP) $(FLAGS) -c program20-4.cpp

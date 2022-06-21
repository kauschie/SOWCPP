COMP = g++
FLAGS = -Wall -std=c++11

all: runme1 runme2 runme3 runme4

clean:
	rm *.exe *.o


runme1: program21-1.cpp IntBinaryTree.o
	$(COMP) $(FLAGS) -o runme1 program21-1.cpp IntBinaryTree.o

runme2: program21-2.cpp IntBinaryTree.o
	$(COMP) $(FLAGS) -o runme2 program21-2.cpp IntBinaryTree.o

runme3: program21-3.cpp IntBinaryTree.o
	$(COMP) $(FLAGS) -o runme3 program21-3.cpp IntBinaryTree.o

runme4: program21-4.cpp IntBinaryTree.o
	$(COMP) $(FLAGS) -o runme4 program21-4.cpp IntBinaryTree.o


IntBinaryTree.o: IntBinaryTree.cpp
	$(COMP) $(FLAGS) -c IntBinaryTree.cpp

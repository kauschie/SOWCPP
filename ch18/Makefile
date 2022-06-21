COMP = g++
FLAGS = -Wall -std=c++11

all: runme1 runme2 runme3 runme4

clean:
	rm *.exe *.o


runme1 : main1.cpp NumberList.o
	$(COMP) $(FLAGS) -o runme1 main1.cpp NumberList.o

runme2 : main2.cpp NumberList.o
	$(COMP) $(FLAGS) -o runme2 main2.cpp NumberList.o

runme3 : main3.cpp NumberList.o
	$(COMP) $(FLAGS) -o runme3 main3.cpp NumberList.o

runme4 : main4.cpp NumberList.o
	$(COMP) $(FLAGS) -o runme4 main4.cpp NumberList.o

NumberList.o : NumberList.h NumberList.cpp
	$(COMP) $(FLAGS) -c NumberList.cpp

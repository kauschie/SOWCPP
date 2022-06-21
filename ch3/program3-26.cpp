// This program simulates rolling a dice
#include <iostream>
#include <cstdlib>	// for rand() and srand() functions
#include <ctime>	// for time() function
using namespace std;

int main() 
{
	const short MIN_VALUE = 1; // Minimum die roll
	const short MAX_VALUE = 6; // Maximum die roll

	int die1;	// To hold the value of die#1
	int die2;	// To hold the value of die#2

	unsigned seed = time(0); // get the system time to seed the random generator
	srand(seed);	// seed the random generator

	cout << "Rolling the dice....\n";
	die1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	die2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	cout << die1 << endl;
	cout << die2 << endl;

	return 0;
}

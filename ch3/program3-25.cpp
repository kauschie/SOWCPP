/* This program demonstrates random numbers */
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // For the time function
using namespace std;

int main()
{
	// Get the system time
	unsigned seed = time(0);
	
	// See the random number generator
	srand(seed);

	// Display three random numbers
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	return 0;
}

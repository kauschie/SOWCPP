// This program demonstrates how floating-point
// round-off errors can make equality operations unreliable.
#include <iostream>
using namespace std;

int main()
{
	double a = 1.5;
	double b = 1.5;

	a+=0.000000000000000001;
	if (a<b)
		cout << "Both a and b are the same" << endl;
	else
		cout << "a and b are not the same\n";
	return 0;
}


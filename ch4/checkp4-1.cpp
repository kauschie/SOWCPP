// Checkpoint 4.1 through x
#include <iostream>
using namespace std;

int main()
{
	// problem 4.1
	cout << "Problem 4.1" << endl;
	bool a;
	int x = 5, y = 6, z = 8;
	// a)
	a = (x == 5); // true (1)
	cout << "My answer: 1, Correct answer: " << a << endl;

	// b)
	a = 7 <= (x+2); // true (1)
	cout << "My answer: 1, Correct answer: " << a << endl;

	// c)
	a = z < 4;	// false (0)	
	cout << "My answer: 0, Correct answer: " << a << endl;
	
	// d)
	a = ((2+x)!=y);	// true(1)
	cout << "My answer: 1, Correct answer: " << a << endl;
	
	// e)
	a = (z != 4);	// true(1)
	cout << "My answer: 1, Correct answer: " << a << endl;

	// f)
	a = (x >= 9); 	// false(0)
	cout << "My answer: 0, Correct answer: " << a << endl;

	// g)
	a = (x <= (y * 2) ); // true(1)
	cout << "My answer: 1, Correct answer: " << a << endl;

	// Problem 4.2
	
	/*
	 * a) false
	 * b) false
	 * c) true
	 */ 

	// Problem 4.3
	//
	//A)    y < x < z	yes
	//B)	y <= x,z	no
	//C)	z != x != y	no
	
	// Problem 4.4
	cout << "----------------------------" << endl;
	cout << "Problem 4.4" << endl;
	int a1 = 0, b = 2, x1 = 4, y1 = 0;

	cout << (a1 == b) << " | 0" << endl;
	cout << (a1 != y1) << " | 0" << endl;
	cout << (b <= x1) << " | 1" << endl;
	cout << (y1 > a1) << " | 0" << endl;




	
	return 0;
}

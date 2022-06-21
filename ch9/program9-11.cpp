// This program uses two functions that accept addresses of 
// variables as arguments
#include <iostream>
using namespace std;

// Function Prototypes
void getNumber(int* num);
void doubleValue(int* num);

int main()
{
    int number;

    // Call getNumber and pass the address of the number.
    getNumber(&number);

    // Call double value and pass the address of number.
    doubleValue(&number);

    // Display the value in number.
    cout << "That value doubled is " << number << endl;

    return 0;
}

void getNumber(int* num)
{
    cout << "Enter an integer number: ";
    cin >> *num;
}

void doubleValue(int* num)
{
    *num *= 2;
}

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

    getNumber(&number);
    doubleValue(&number);
    
    cout << "The number is now: " << number << endl;

    return 0;
}

void getNumber(int* num)
{
    cout << "Enter a number: ";
    cin >> *num;
}
void doubleValue(int* num)
{
    *num *= 2;
}

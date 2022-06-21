#include <iostream>
#include <string>
using namespace std;

// function prototype
double divide(int, int);

int main()
{
    int num1, num2; // to hold two ints
    double quotient;  // to hold the quotient of the numbers

    // get two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Divide num1 by num2 and catch any potential exceptions
    try
    {
        quotient = divide(num1, num2);
        cout << "The quotient is " << quotient << endl;
    }
    catch( string exceptionString)
    {
        cout << exceptionString;
    }
    cout << "End of the program.\n";

    return 0;
}

double divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        string exceptionString = "ERROR: Cannot divide by zero.\n";
        throw exceptionString;
    }

    return static_cast<double>(numerator) / denominator;
}

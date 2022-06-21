// This program demonstrates that changes to a function parameter
// have no effect to the original argument
#include <iostream>
using namespace std;

// Function prototype
void changeMe(int);

int main()
{
    int number = 12;

    // Display the value in number
    cout << "The number is " << number << endl;

    // Call changeMe, passing the value in number as an arg
    changeMe(number);

    // Display the value in number again
    cout << "Now back in main again, the value of\n"
        << "number is " << number << endl;
    return 0;
}

void changeMe(int myValue)
{
    // Change the value of myValue to 0
    myValue = 0;

    // Display the value in myValue
    cout << "In function changeMe\n";
    cout << "Now the value is " << myValue << endl;
}

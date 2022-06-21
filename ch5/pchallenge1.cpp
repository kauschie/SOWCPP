// M. Kausch
// Ch.5 Programming Challenge 1
// 9/5/2021
#include <iostream>
using namespace std;

int main()
{
    int number = 0,
        sum = 0;

    cout << "Enter a positive number: ";
    cin >> number;

    while (number < 0)
    {
        cout << "You must enter a positive number.\n";
        cout << "Enter a positive number: ";
        cin >> number;
    }
    for (int i = 1; i <= number; i++)
        sum += i;

    cout << "The sum from 1 to " << number 
        << " is: " << sum << endl;

    return 0;
}


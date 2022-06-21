// Checkpoint ##
//
#include <iostream>
using namespace std;

int main()
{
    int minNumber,
        maxNumber;

    cout << "I will display a table of numbers and their squares.\n"
        << "Enter the starting number: ";
    cin >> minNumber;
    cout << "Enter the ending number: ";
    cin >> maxNumber;

    // Display the table.

    cout << "Number Number Squared\n"
        << "------------------------\n";

    for (int i = minNumber; i <= maxNumber; i++)
        cout << i << "\t\t" << i*i << endl;


    return 0;
}


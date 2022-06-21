// This program uses a range based for loop
// to modify the contents of an array.
#include <iostream>
using namespace std;

int main()
{
    int numbers[5];

    // Get values for the array
    for (int &val : numbers)
    {
        cout << "Enter an integer value: ";
        cin >> val;
    }

    // Display the contents of the array.
    cout << "Here are the values you entered:\n";
    for (int val : numbers)
        cout << val << endl;

}


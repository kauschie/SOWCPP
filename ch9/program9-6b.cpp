// This program processes an array using pointer notation
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5; // size of the array
    int numbers[SIZE]; // array of ints
    int count;

    // get values to store in the array.
    // use pointer notation instead of subscripts
    cout << "Enter " << SIZE << " numbers\n";
    for (count = 0; count < SIZE; count++)
    {
        cout << "Number" << count+1 << ": ";
        cin >> *(numbers + count);
    }

    cout << "Here are the numbers you entered:\n";
    // display numbers using pointer notation.
    for (count = 0; count < SIZE; count++)
    {
        cout << "Number" << count+1 << ": ";
        cout << *(numbers+count) << endl;
    }

    return 0;
}

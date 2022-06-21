// This program uses a pointer to display the contents
// of an integer array
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 8;
    int numbers[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};
    int* ptr = numbers;     // make ptr point to number

    // display the numbers in the array
    cout << "The numbers are:\n";

    while (ptr < &numbers[SIZE-1])
    {
        cout << *ptr << " ";
        ptr++;
    }
    cout << *ptr;
    // Display the numbers in reverse order
    cout << "\nThe numbers backwards are:\n";

    while (ptr > numbers)
    {
        cout << *ptr << " ";
        ptr--;
    }
    cout << *ptr;

    return 0;
}

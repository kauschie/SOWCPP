// This program uses subscript notation with a pointer variable and
// pointer notation with an accay name.
#include <iostream>
using namespace std;

int main()
{
    const int NUM_COINS = 5;
    double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};
    double* doublePtr;  // Pointer to a double
    int count;          // Array index

    // Assign the address of the coins array to doublePtr
    doublePtr = coins;

    // Display the contents of the coins array. Use subscripts
    // with the pointer!

    cout << "Here are the values in the coins array:\n";
    for (count = 0; count < NUM_COINS; count++)
        cout << doublePtr[count] << " ";
    cout << endl << endl;
    // display the contents of the array again, but this time
    // use the pointer notation with the array name!

    for (count = 0; count < NUM_COINS; count++)
        cout << *(coins + count) << " ";
    cout << endl << endl;
    return 0;
}

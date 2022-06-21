// This program uses the address of each element in the array
#include <iostream>
using namespace std;

int main()
{
    const int NUM_COINS = 6;
    double coins[NUM_COINS] = {0.01, 0.05, 0.1, 0.25, 0.5, 1.0};
    double* doublePtr = nullptr;        // Pointer to a double
    int count;

    // use the pointer to display the values in the array
    for (count = 0; count < NUM_COINS; count++)
    {
        // Get the address of the array element
        doublePtr = &coins[count];
        cout << "The address of coins[" << count << "] is: "
            << &coins[count] << " or " << doublePtr << endl;
        cout << "The value is: " << *(coins+count) << " or " << *doublePtr << endl;

    }

    cout << endl;

    return 0;
}

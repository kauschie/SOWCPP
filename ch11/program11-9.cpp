// This program demonstrates an enumerated data type.
#include <iostream>
#include <iomanip>
using namespace std;

enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

int main()
{
    const int NUM_DAYS = 5;         //  num of days
    double sales[NUM_DAYS];     // holds sales for each day
    double total = 0.0;         // accumulator
    int index;                  // loop counter

    // get the sales for each day
    for (index = MONDAY; index <= FRIDAY; index++)
    {   
        cout << "Enter the sales for day " << index + 1 << ": ";
        cin >> sales[index];
    }

    // calculate the total sales
    for (index = MONDAY; index <= FRIDAY; index++)
    {
        total += sales[index];
    }


    // Display the total.
    cout << "The total sales are $" << fixed << showpoint
            << setprecision(2) << total << endl;

    return 0;
}

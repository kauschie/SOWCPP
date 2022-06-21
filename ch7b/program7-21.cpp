// This program demonstrates a two dimensional array
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int NUM_DIVS = 3;     // divisions
    const int NUM_QTRS = 4;     // quarters
    double sales[NUM_DIVS][NUM_QTRS];   // 3 rows 4 columns
    double totalSales = 0;      // accumulator for total sales
    int div, qtr;               // loop counters

    cout << "this program will calculate the total sales of\n"
        << " all the company's divisions.\n"
        << "Enter the following sales information:\n\n";

    // nested loop to fill the array with quarterly sales
    // figures from each division.
    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            cout << "Division: " << div+1;
            cout << ", Quarter: " << qtr + 1 << ": $";
            cin >> sales[div][qtr];
        }
        cout << endl;    
    }

    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
            totalSales += sales[div][qtr]; 
    }

    cout << fixed << showpoint << setprecision(2);
    cout << "The total sales for the company are: $" << totalSales << endl;
    return 0;
}


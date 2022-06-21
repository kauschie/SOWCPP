// This program demonstrates that a pointer may be used as a
// parameter to accept the address of an array.
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void getSales(double* salesArr, int size);
double totalSales(double* salesArr, int size);


int main()
{
    const int QTRS = 4;
    double sales[QTRS];

    // get the sales data for all quarters.
    getSales(sales, QTRS);

    // set the numeric output formatting
    cout << fixed << showpoint << setprecision(2);

    // Display the total sales for the year.
    cout << "The total sales for the year are $";
    cout << totalSales(sales, QTRS) << endl;

    cout << "The sales array is still: " << sales << endl;
    return 0;
}

void getSales(double* salesArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the sales figures for quarter " << (i+1) << ": ";        
        cin >> salesArr[i];
    }
}

double totalSales(double* salesArr, int size)
{
    int sum = 0;
    cout << "Sales Arr is currently " << salesArr << endl;

    for (int i = 0; i < size; i++, salesArr++)
    {
        sum += *salesArr;
    }

    cout << "Sales Arr is now " << salesArr << endl;
    return sum;
}


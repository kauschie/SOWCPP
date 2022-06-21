// programming challenge 7, chapter 5
// michael kausch
// 9/6/21
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int days_worked = 0;
    double pay = 0.01;

    cout << fixed << showpoint << setprecision(2);
    cout << "Enter how many days you have worked: ";

    while (!(cin >> days_worked) || days_worked < 1)
    {
        cout << "The number of days worked needs to be greater than 1\n"
            << "Enter how many days you have worked: ";
    }

    cout << "Day\t\t\tPay Rate\n"
        << "--------------------\n";
    
    for (int i = 1; i <= days_worked; i++)
    {
        pay += 2*i;
        cout << i << "\t\t\t" << pay << endl;
    }

    return 0;
}


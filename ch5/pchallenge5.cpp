// Programming challenge 5
// chapter 5
// michael kausch
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const int YEAR = 2021;
    double current_rate = 2500.00;
    const float P_INCREASE = 0.04;

    cout << "Year\t\tCost\n";
    cout << "-----------------\n";

    for (int i = 0; i < 6; i++)
    {
        current_rate += (current_rate * P_INCREASE);
        cout << YEAR + i << "\t\t" << current_rate << endl;
    }

    return 0;
}


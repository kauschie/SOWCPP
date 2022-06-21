// programming challenge 3
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double OCEAN_INC = 1.5;
    const int YEAR = 2021;
    
    cout << "Year\t\tAmount Risen\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < 25; i++)
    {
        cout << YEAR + i << "\t\t" 
            << i * OCEAN_INC << endl;
    }
    cout << endl;

    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const float CAL_BURN_RATE = 3.6;    // cal / min

    cout << "Time\t\tCalories Burned\n";
    cout << fixed << showpoint << setprecision(1);
    for (int i = 0; i <= 30; i+=5)
    {
        if (i>0)
            cout << i << "\t\t" << i*CAL_BURN_RATE << endl;
    }
    


    return 0;
}


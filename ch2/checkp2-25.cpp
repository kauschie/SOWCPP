// A program exploring constants
#include <iostream>
using namespace std;

int main()
{
    const float E = 2.71828;
    const int MINUTES_IN_A_YEAR = 5.256E5;
    const float g_english = 32.2;
    const float g_metric = 9.8;
    const int mile_in_meters = 1609;

    cout << "e: " << E << endl;
    cout << "year in minutes: " << MINUTES_IN_A_YEAR << endl;
    cout << "gravitational acceleration (in ft/s^2): " << g_english << endl;
    cout << "gravitational acceleration (in m/s^2): " << g_metric << endl;
    cout << "Number of meters in a mile: " << mile_in_meters << endl;
    return 0;
}
// program challenge 6, chapter 5
// mike kausch
// 9/6/21
#include <iostream>
using namespace std;

int main()
{
    double veh_speed = 0;
    double t_traveled = 0;
    
    cout << "This program calculates the distance traveled\n"
        << "Enter the speed of the vehicle (mph): ";

    while (!(cin >> veh_speed) || veh_speed < 0)
        cout << "You need to enter a non-negative number: ";

    cout << "Enter how long the vehicle has\n"
        << "been traveling in hours: ";

    while (!(cin >> t_traveled) || t_traveled < 1)
        cout << "You need to enter a number greater than 1: ";

    cout << "Hour\tDistance Traveled\n"
        << "--------------------------\n";
    for (int i = 1; i <= t_traveled; i++)
        cout << i << "\t\t" << i * veh_speed << endl;

    return 0;
}


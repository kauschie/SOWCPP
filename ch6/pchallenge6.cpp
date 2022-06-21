// chapter 6 programming challenge 6
// 9/19/21
// m.kausch
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

double kineticEnergy(double, double);

int main()
{
    double mass,
           velocity,
            KE;

    cout << "I calculate the kinetic energy of an object.\n"
        << "Enter the mass in kg: ";
    cin >> mass;
    cout << "Enter the velocity in meters/second: ";
    cin >> velocity;
    KE = kineticEnergy(mass, velocity);
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "The kinetic energy is " << KE << endl;

    return 0;
}

double kineticEnergy(double m, double v)
{
    return ((m* pow(v,2)) / 2);
}

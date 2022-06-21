// This program converts cups to fluid ounces
#include <iostream>
#include <iomanip>
using namespace std;

// define function prototypes
void showIntro();
double getCups();
double cupsToOunces(double cups);

int main()
{
    double cups, ounces;
    cout << fixed << showpoint << setprecision(1);
    showIntro();
    cups = getCups();
    ounces = cupsToOunces(cups);
    cout << cups << " cups equals " << ounces << " ounces.\n";

    return 0;

}

void showIntro()
{
    cout << "This program converts measurements\n"
        << "in cups to fluid ounces. For your\n"
        << "reference the formula is:\n"
        << " 1 cup = 8 fluid ounces\n\n";
}

double getCups()
{
    double numCups;
    cout << "Enter the number of cups: ";
    cin >> numCups;
    return numCups;
}

double cupsToOunces(double numCups)
{
    return (numCups * 8.0);
}

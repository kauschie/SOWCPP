// This program is a driver for testing the showFees function.
#include <iostream>
using namespace std;

// Prototype
void showFees(double, int);

int main()
{
    // Constants for membership rates
    const double ADULT = 40.0;
    const double SENIOR = 30.0;
    const double CHILD = 20.0;

    // perform a test for adult membership.
    cout << "Testing an adult membership...\n"
        << "Calling the showFees function with arguments "
        << ADULT << " and 10.\n";
    showFees(ADULT, 10);

    // perform a test for senior citizen membership
    cout << "\nTesting a senior citizen membership...\n"
        << "Calling the showFees function with arguments "
        << SENIOR << " and 10.\n";
    showFees(SENIOR, 10);

    // perform a test for child membership
    cout << "\nTesting a child membership...\n"
        << "Calling the showFees function with arguments "
        << CHILD << " and 10.\n";
    showFees(CHILD, 10);

    return 0;
}

void showFees(double memberRate, int months)
{
    cout << "The total charges are $"
        << (memberRate * months) << endl;
}


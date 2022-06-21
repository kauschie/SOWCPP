// this program uses a function template
#include <iostream>
#include <iomanip>
using namespace std;

// template definition for square function
template <class T>
T square(T number)
{
    return number*number;
}

int main()
{
    int userInt;
    double userDouble;

    cout << setprecision(5);
    cout << "Enter an integer and a floating-point value: ";
    cin >> userInt >> userDouble;
    cout << "Here are their squares: ";
    cout << square(userInt) << " and "
        << square(userDouble) << endl;
    return 0;
}

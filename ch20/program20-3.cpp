#include <iostream>
using namespace std;

int factorial(int);

int main()
{

    int number;
    cout << "enter an integer val and I will display\nits factorial: ";
    cin >> number;

    // Display the factorial of the number
    cout << "The factorial of " << number << " is ";
    cout << factorial(number) << endl;

    return 0;
}

int factorial(int n)
{
    if (n==0)
        return 1;
    else
    {
        return n * factorial(n-1);
    }
}

// type cast expression to print a char from a number
#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number see it's' corresponding ASCII value: ";
    cin >> number;
    cout << "The ASCII value for " << number << " is ";
    cout << static_cast<char>(number) << endl;
    return 0;
}
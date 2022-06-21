#include <iostream>
using namespace std;
int main()
{
    int userNum;
    cout << "Enter one of the numbers 1, 2, or 3: ";
    cin >> userNum;

    switch (userNum)
    {
        case 1: cout << "one\n";
                break;
        case 2: cout << "two\n";
                break;
        case 3: cout << "three\n";
                break;
        default: cout << "you entered the wrong shit jackass";
    }
    return 0;
}


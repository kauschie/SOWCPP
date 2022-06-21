#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string1, string2;

    cout << "Enter your first string: ";
    cin >> string1;
    cout << "Enter your second string: ";
    cin >> string2;
    if (string1 < string2)
    {
        cout << "String 1 is less than string 2" << endl;
    }
    else if (string1 > string2)
    {
        cout << "String 1 is greater than string 2" << endl;
    }
    else
    {
        cout << "String 1 must be equal to string 2" << endl;
    }
    return 0;
}


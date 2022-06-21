// This program demonstrates a function with three params
#include <iostream>
using namespace std;

// function prototype
void showSum(int, int, int);

int main()
{
    int value1, value2, value3;
    
    // get three integeters
    cout << "Enter three integers and I will display ";
    cout << "their sum: ";
    cin >> value1 >> value2 >> value3;

    // call showSum passing three arguments.
    showSum(value1, value2, value3);
    
    return 0;
}

void showSum(int num1, int num2, int num3)
{
    cout << (num1 + num2 + num3) << endl;
}


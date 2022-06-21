//This program shows that a global variable is visible
//to all the functions that appear in a program after
//the variable's declaraion.
#include <iostream>
using namespace std;

void anotherFunction(); // function prototype
int num = 2;            // global variable

int main()
{
    cout << "In main, num is " << num << endl;
    anotherFunction();
    cout << "Back in main, num is " << num << endl;
    return 0;
}

void anotherFunction()
{
    cout << "In anotherFunction, num is " << num << endl;
    num = 50;
    cout << "But, it is now changed to " << num << endl;
}


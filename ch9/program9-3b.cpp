// This program demonstrates the use of the indirection operator
#include <iostream>
using namespace std;

int main()
{
    int x = 25;
    int *ptr = nullptr;  // pointer variable, can point to an int

    ptr = &x;       // store the address of x in ptr

    // use both x and ptr to display the value in x
    cout << "Here is the value of x printed twice:\n";
    cout << x << endl;         // displays the contents of x
    cout << *ptr << endl;          // displays the contents of x

    // assign 100 to the location pointed to by ptr.
    // this will assign 100 to x

    *ptr = 100;

    cout << "Once again here are the values in x:\n";
    cout << x << endl;     // displays the contents of x
    cout << *ptr << endl; // displays the contents of x
    cout << ptr << endl;

    return 0;
}

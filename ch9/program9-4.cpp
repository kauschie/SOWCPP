// This program demonstrates a pointer variable referencing different values
#include <iostream>
using namespace std;

int main()
{
    int x = 25, y = 50, z = 75;
    int* ptr = nullptr;

    cout << "Here are the values of x, y and z\n";
    cout << x << " " << y << " " << z << endl;

    // use the pointer to manipulate x,y, and z

    ptr = &x;
    \
    *ptr += 100;    // add 100 to the value in x

    ptr = &y;
    *ptr += 100;    // add 100 to the value in y

    ptr = &z;
    *ptr += 100;    // add 100 to the value in z

    cout << "Here are the values of x, y and z\n";
    cout << x << " " << y << " " << z << endl;

    return 0;
}

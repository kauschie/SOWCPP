// This program demonstrates the use of the indirection operator
#include <iostream>
using namespace std;

int main()
{
    int x = 25;
    int* ptr = &x;

    cout << "x is " << *ptr << endl;
    cout << "ptr is pointing to " << ptr << endl;
    cout << "which is x's addres see " << &x << endl;
    
    *ptr *= 4;

    cout << "x multiplied by 4 is : " << x << endl;
    cout << "gonna display it using the pointer, see: " << *ptr << endl;

    int y = 30;

    cout << "uht oh, y came in the picture with " << y << " bones bro\n";
    
    ptr = &y;

    cout << "ptr is now pointing to y and here's its value: " << *ptr << endl;
    cout << "here is y's address: " << ptr << " and " << &y << endl;
    cout << "and here is x's address: " << &x << endl;


    return 0;
}

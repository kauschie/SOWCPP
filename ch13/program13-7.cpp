#include <iostream>
#include <cstdlib>
#include "rectangle.h"
using namespace std;

// class definitions


int main()
{

    Rectangle box;      // define an instance of the Rectangle class

    // Display the rectangle's data
    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;

    return 0;
}

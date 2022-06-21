// ths program demonstrates Rectangle class Exceptions
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    double width;
    double length;

    Rectangle myRectangle;

    // get the width and length;

    cout << "Enter the Rectangle's width: ";
    cin >> width;
    cout << "Enter the Rectangle's length: ";
    cin >> length;

    // store these values into the rectangle Object
    try
    {
        myRectangle.setWidth(width);
        myRectangle.setLength(length);
        cout << "The area of the rectangle is "
            << myRectangle.getArea() << endl;
    }
    catch (Rectangle::NegativeWidth)
    {
        cout << "ERROR: A negative value was entered "
        << "for the rectangle's width.\n";
    }
    catch (Rectangle::NegativeLength)
    {
        cout << "ERROR: A negative value was entered "
        << "for the rectangle's length.\n";
    }
    
    cout << "End of the program.\n";

    return 0;
}

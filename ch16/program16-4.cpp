// ths program demonstrates Rectangle class Exceptions
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    double width;
    double length;
    bool tryAgain = true;   // flag to reread input

    Rectangle myRectangle;

    // get the width and length;
    cout << "Enter the Rectangle's width: ";
    cin >> width;
    while (tryAgain)
    {
        try
        {
            myRectangle.setWidth(width);
            // if no exception was thrown then the next statement
            // will execute.
            tryAgain = false;
        }
        catch (Rectangle::NegativeWidth)
        {
            cout << "Please enter a nonnegative value: ";
            cin >> width;
        }
    }

    cout << "Enter the Rectangle's length: ";
    cin >> length;
    tryAgain = true;

    while (tryAgain)
    {
        try
        {
            myRectangle.setLength(length);
            tryAgain = false;
        }
        catch (Rectangle::NegativeLength)
        {
            cout << "Please enter a nonnegative value: ";
            cin >> length;
        }
    }
    // store these values into the rectangle Object

    cout << "The area of the rectangle is "
        << myRectangle.getArea() << endl;
    return 0;
}

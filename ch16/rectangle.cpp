// Implementation file for the Rectangle class.
#include <iostream>     // needed for cout
#include <cstdlib>      // needed for the exit function
#include "Rectangle.h"  // needed for the rectangle class

Rectangle::Rectangle()
{
    width = 0.0;
    length = 0.0;
}

Rectangle::Rectangle(double w, double l)
{
    width = w;
    length = l;
}

void Rectangle::setWidth(double w)
{
    if (w >= 0)
        width = w;
    else
        throw NegativeWidth(w);
}

void Rectangle::setLength(double l)
{
    if (l >= 0)
        length = l;
    else
        throw NegativeLength(l);   // causes instance of NegativeSize
            // class to be created and thrown as an exception
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const
{
    return width * length;
}

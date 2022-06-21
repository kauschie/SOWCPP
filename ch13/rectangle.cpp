// Implementation file for the Rectangle class.
#include <iostream>     // needed for cout
#include <cstdlib>      // needed for the exit function
#include "Rectangle.h"  // needed for the rectangle class

Rectangle::Rectangle()
{
    width = 10; 
    length = 12;
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
    {
        std::cout << "Invalid width\n";
        exit(EXIT_FAILURE);
    }
}

void Rectangle::setLength(double l)
{
    if (l >= 0)
        length = l;
    else 
    {
        std::cout << "Invalid length\n";
        exit(EXIT_FAILURE);
    }
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


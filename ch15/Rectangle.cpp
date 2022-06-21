#include <iostream>
#include "Rectangle.h"
using namespace std;

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
        cout << "Invalid width\n";
        exit(EXIT_FAILURE);
    }
}

void Rectangle::setLength(double l)
{
    if (l >= 0)
        length = l;
    else
    {
        cout << "Invalid length\n";
        exit(EXIT_FAILURE);
    }
}
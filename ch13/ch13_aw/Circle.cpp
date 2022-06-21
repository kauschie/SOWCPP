#include <iostream>
#include "Circle.h"


Circle::Circle()
{
    radius = 0;
}
Circle::Circle(double r)
{
    radius = r;
}
double Circle::getRadius()
{
   return radius; 
}

void Circle::setRadius(double r)
{
    radius = r;
}

double Circle::getArea()
{
    return 3.14159 * radius * radius;
}

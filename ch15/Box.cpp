#include "Box.h"

Box::Box() : Rectangle()
{ 
    height = 0.0; volume = 0.0; 
}

Box::Box(double w, double len, double h) : Rectangle(w, len)
{ 
    height = h;
    volume = getArea() * h;
}

double Box::getHeight()
{ 
    return height; 
}

double Box::getVolume()
{ 
    return volume; 
}

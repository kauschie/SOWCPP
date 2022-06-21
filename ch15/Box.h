#ifndef BOX_H
#define BOX_H
#include "Rectangle.h"

class Box : public Rectangle
{
    protected:
        double height;
        double volume;

    public:
        // default constructor
        Box();
        Box(double w, double len, double h);
        double getHeight();
        double getVolume();
};
#endif
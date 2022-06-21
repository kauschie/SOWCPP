#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    private:
        double radius;
        double area;

    public:
        Circle();
        Circle(double r);
        double getRadius();
        void setRadius(double r);
        double getArea();
};


#endif

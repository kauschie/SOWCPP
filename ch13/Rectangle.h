    // Specification file for the Rectangle class
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    private:
        double width;
        double length;

    public:
        Rectangle();
        Rectangle(double, double);                    // constructor - Note: the args
        void setWidth(double w);
        void setLength(double l);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

#endif

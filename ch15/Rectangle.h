#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    private:
        double width;
        double length;

    public:
        Rectangle()
        {  width = length = 0.0;  }
        Rectangle(double, double);                    // constructor - Note: the args
        void setWidth(double w);
        void setLength(double l);
        double getWidth() const { return width; }
        double getLength() const { return length; }
        double getArea() const { return length * width; }
};

#endif
    // Specification file for the Rectangle class
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    private:
        double width;
        double length;

    public:
        // exception Class
        class NegativeWidth  // exception for neg width
            {
            private:
                double value;
            public:
                NegativeWidth(double val)
                    { value = val; }
                double getValue() const
                { return value; }
            };
        // exception class
        class NegativeLength    // exception for neg length
            {
            private:
                double value;
            public:
                NegativeLength(double val)
                    { value = val; }
                double getValue() const
                    { return value; }
            };

        Rectangle();
        Rectangle(double, double);  // constructor - Note: the args
        void setWidth(double w);
        void setLength(double l);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

#endif

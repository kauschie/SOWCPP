// This program demonstrates a simple class
#include <iostream>
using namespace std;

// class definitions
class Rectangle
{
    private:
        double width;
        double length;

    public:
        void setWidth(double w);
        void setLength(double l);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

void Rectangle::setWidth(double w)
{
    width = w;
}

void Rectangle::setLength(double l)
{
    length = l;
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

int main()
{
    string s;
    Rectangle box;
    double rectWidth;
    double rectLength;

    cout << "This program will calculate the area of a\n"
        << "rectangle. What is the width? ";
    cin >> rectWidth;
    cout << "What is the length? ";
    cin >> rectLength;

    box.setWidth(rectWidth);
    box.setLength(rectLength);
    
    Rectangle * bp = new Rectangle;
    

    // Display the rectangles data
    cout << "Here is the rectangles data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;

    return 0;
}


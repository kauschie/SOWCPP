// This program creates three instances of the Rectangle class
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
    double number;
    double totalArea;

    Rectangle *kitchen = nullptr,            // defines 3 Rectangle objects
              *bedroom = nullptr, 
              *den = nullptr;

    // dynamically allocate the object
    kitchen = new Rectangle;
    bedroom = new Rectangle;
    den = new Rectangle;

    // Get the kichen's dimension? 
    cout << "What is the kitchen's length? ";
    cin >> number;
    kitchen->setLength(number);
    cout <<"What is the kitchen's width? ";
    cin >> number;
    kitchen->setWidth(number);

    // Get the bedroom's dimension? 
    cout << "What is the bedroom's length? ";
    cin >> number;
    bedroom->setLength(number);
    cout <<"What is the bedroom's width? ";
    cin >> number;
    bedroom->setWidth(number);

    // Get the den's dimension? 
    cout << "What is the den's length? ";
    cin >> number;
    den->setLength(number);
    cout <<"What is the den's width? ";
    cin >> number;
    den->setWidth(number);

    totalArea = kitchen->getArea() + bedroom->getArea() + den->getArea();

    cout << "The total area of the three rooms is " << totalArea << endl;

    delete kitchen;
    delete bedroom;
    delete den;

    kitchen = nullptr;
    bedroom = nullptr;
    den = nullptr;

    return 0;
}



// This program creates three instances of the same class
#include <iostream>
using namespace std;

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

  Rectangle kitchen,            // defines 3 Rectangle objects
            bedroom, 
                den;

      // Get the kichen's dimension? 
    cout << "What is the kitchen's length? ";
    cin >> number;
    kitchen.setLength(number);

    cout <<"What is the kitchen's width? ";
    cin >> number;
    kitchen.setWidth(number);

      // Get the bedroom's dimension? 
    cout << "What is the bedroom's length? ";
    cin >> number;
    bedroom.setLength(number);

    cout <<"What is the bedroom's width? ";
    cin >> number;
    bedroom.setWidth(number);

      // Get the den's dimension? 
    cout << "What is the den's length? ";
    cin >> number;
    den.setLength(number);

    cout <<"What is the den's width? ";
    cin >> number;
    den.setWidth(number);

    totalArea = kitchen.getArea() + bedroom.getArea() + den.getArea();

    cout << "The total area of the three rooms is " << totalArea << endl;

    return 0;
}



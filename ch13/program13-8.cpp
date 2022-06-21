#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Rectangle.h"

using namespace std;

int main()
{
    double houseWidth, houseLength;

    // get the width and length of the house
    cout << "in feet, how wide is your house? ";
    cin >> houseWidth;
    cout << "In feet, how long is your house? ";
    cin >> houseLength;

    
    Rectangle house(houseWidth, houseLength);      // define an instance of the Rectangle class

    // Display the house's data
    cout << setprecision(2) << fixed;
    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << house.getWidth() << endl;
    cout << "Length: " << house.getLength() << endl;
    cout << "Area: " << house.getArea() << endl;

    return 0;
}

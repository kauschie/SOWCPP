#include <iostream>
#include "Box.h"
#include "Rectangle.h"
using namespace std;


int main()
{
    double boxWidth, boxLength, boxHeight;

    // get the measurements from the user
    cout << "Enter the dimensions of the box:\n"
        << "Width: ";
    cin >> boxWidth;
    cout << "Length: ";
    cin >> boxLength;
    cout << "Height: ";
    cin >> boxHeight;

    // define a box object
    Box myBox(boxWidth, boxLength, boxHeight);

    // display the box object's properties
    cout << "Here are the box's properties:\n";
    cout << "Width: " << myBox.getWidth() << endl;
    cout << "Length: " << myBox.getLength() << endl;
    cout << "Height: " << myBox.getHeight() << endl;
    cout << "Base Area: " << myBox.getArea() << endl;
    cout << "Volume: " << myBox.getVolume() << endl;

    return 0;
}

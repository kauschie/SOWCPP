// main for algo workbench
// attempting to use makefiles
#include <iostream>
#include "Circle.h"

using namespace std;

void print_circles(Circle * c);

int main()
{

    Circle * circles = new Circle[5];

    Circle * moreCircles = new Circle[5] {12, 7, 9, 14, 8};

    print_circles(circles);
    print_circles(moreCircles);


    delete [] circles;
    circles = nullptr;

    delete [] moreCircles;
    moreCircles = nullptr;

    return 0;
}

void print_circles(Circle * c)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Area of Circle" << i+1 << " is: " << c[i].getArea() << endl;
    }
}


// Question 49:
// Animal
// Doctor
// Patient
// Medication
// Invoice
// Client
// Nurse
// Customer
//
// Question 50:
//

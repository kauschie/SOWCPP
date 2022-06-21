// this program demonstrates the car, truck and suv classes
// that are derived from the automobile class

#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
#include "Automobile.h"

int main()
{
    Car car("BMW", 2007, 50000, 15000.0, 4);
    Truck truck("Toyota", 2006, 40000, 12000.0, "4WD");
    SUV suv("Volvo", 2005, 30000, 18000.0, 5);

    cout << fixed << showpoint << setprecision(2);
    cout << "We have the following car in inventory:\n"
        << car.getModel() << " " << car.getMake() << " with "
        << car.getDoors() << " doors and " << car.getMileage()
        << " miles.\nPrice: $" << car.getPrice() << endl << endl;

    cout << "We have the following truck in inventory:\n"
        << truck.getModel() << " " << truck.getMake() << " with "
        << truck.getDriveType() << " drive type and " << truck.getMileage()
        << " miles.\nPrice: $" << truck.getPrice() << endl << endl;

    cout << "We have the following car in inventory:\n"
        << suv.getModel() << " " << suv.getMake() << " with "
        << suv.getMileage() << " miles and " << suv.getPassengers() 
        << " passenger capacity.\nPrice: $" << suv.getPrice() << endl;

    return 0;
}

#ifndef CAR_H
#define CAR_H
#include "Automobile.h"
#include <string>

class Car : public Automobile
{
    private:
        int doors;
    public:
        // default ctor
        Car() : Automobile()
        { doors = 0; }

        // ctor #2
        Car(string carMake, int carModel, int carMileage, double carPrice, int carDoors) :
            Automobile(carMake, carModel, carMileage, carPrice)
            { doors = carDoors; }

        // accessor for doors attribute
        int getDoors()
        { return doors; }
};
#endif
#ifndef TRUCK_H
#define TRUCK_H
#include "Automobile.h"
#include <string>
using namespace std;

class Truck : public Automobile
{
    private:
        string driveType;
    
    public:
        // default ctor
        Truck() : Automobile() { driveType = ""; }

        // ctor #2
        Truck(string truckMake, int truckModel, int truckMileage, double truckPrice, string truckDriveType) :
            Automobile(truckMake, truckModel, truckMileage, truckPrice)
            { driveType = truckDriveType; }

        string getDriveType() { return driveType; }

};

#endif
#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
using namespace std;

class Automobile
{
    private:
        string make;
        int model;
        int mileage;
        double price;

    public:
        // default ctor
        Automobile()
        {  make = "";
            model = 0;
            mileage = 0;
            price = 0.0;  }

        // ctor2
        Automobile(string autoMake, int autoModel, int autoMileage, double autoPrice)
        {
            make = autoMake;
            model = autoModel;
            mileage = autoMileage;
            price = autoPrice;
        }

        // accessors
        string getMake() { return make; }
        int getModel() { return model; }
        int getMileage() { return mileage; }
        double getPrice() { return price; }
};
#endif
#include <iostream>
#include <cstdlib>      // for abs()
using namespace std;

class FeetInches
{
    private:
        int feet;
        int inches;
        void simplify(); 
    public:
        // constructor
        FeetInches(int f = 0, int i = 0)
        {
            feet = f;
            inches = i;
            simplify();
        }

        // Mutators
        void setFeet(int f)
        { feet = f; }

        void setInches(int i)
        { inches = i; 
            simplify(); }

        // Accessor functions
        int getFeet() const
        { return feet; }

        int getInches() const
        { return inches; }

        FeetInches operator+(const FeetInches &);   // Overloaded function
        FeetInches operator-(const FeetInches &);   // Overloaded function
        FeetInches operator++();                    // Overloaded Function ++ prefix operator
        FeetInches operator++(int);                    // Overloaded Function ++ postfix operator

};

void FeetInches::simplify()
{
    if (inches >=12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

FeetInches FeetInches::operator++(int)  // postfix
{
    FeetInches temp(feet, inches);
    inches++;
    simplify();
    return temp;
}



FeetInches FeetInches::operator++()
{
    ++inches;
    simplify();
    return *this;
}

FeetInches FeetInches::operator+(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

FeetInches FeetInches::operator-(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}


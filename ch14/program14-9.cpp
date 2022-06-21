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
        FeetInches operator++();    // prefix
        FeetInches operator++(int);  // postfix
        bool operator>(const FeetInches &right);
        bool operator<(const FeetInches &right);
        bool operator==(const FeetInches &right);
};

bool FeetInches::operator>(const FeetInches &right)
{
    bool status;

    if (feet > right.feet)
        status = true;
    else if (feet == right.feet && inches > right.inches)
        status = true;
    else 
        status = false;

    return status;
}

bool FeetInches::operator<(const FeetInches &right)
{
    bool status;

    if (feet < right.feet)
        status = true;
    else if (feet == right.feet && inches < right.inches)
        status = true;
    else 
        status = false;

    return status;
}

bool FeetInches::operator==(const FeetInches &right)
{
    return (feet == right.feet && inches == right.inches)
}

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

int main()
{
    int count;
    int feet, inches;

    FeetInches first;

    FeetInches second(1, 5);

    // Use the prefix ++ operator.
   
    cout << "Demonstrating prefix ++ operator.\n";

    for (count = 0; count < 12; count++)
    {   
        first = ++second;
        cout << "first: " << first.getFeet() << " feet, ";
        cout << first.getInches() << " inches. ";
        cout << "second: " << second.getFeet() << " feet, ";
        cout << second.getInches() << " inches.\n";
    }

    cout << "\nDemonstrating postfix ++ operator.\n";

    for (count = 0; count < 12; count++)
    {   
        first = second++;
        cout << "first: " << first.getFeet() << " feet, ";
        cout << first.getInches() << " inches. ";
        cout << "second: " << second.getFeet() << " feet, ";
        cout << second.getInches() << " inches.\n";
    }


    return 0;
}

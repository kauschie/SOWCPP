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
    return (feet == right.feet && inches == right.inches);
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
    int feet, inches;

    FeetInches first, second;

    cout << "Enter a distance in feet and inches: ";
    cin >> feet >> inches;

    // Store the distance in first
    first.setFeet(feet);
    first.setFeet(inches);

    // get another distance

    cout << "Enter another distance in feet and inches: ";
    cin >> feet >> inches;

    // Store the distance in first
    second.setFeet(feet);
    second.setFeet(inches);

    // compare the two objects
    if (first == second)
        cout << "first is equal to second.\n";
    else if (first > second)
        cout << "first is greater than second.\n";
    else if (first < second)
        cout << "first is less than second.\n";



    return 0;
}

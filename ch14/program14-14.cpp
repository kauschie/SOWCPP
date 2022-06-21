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
        friend ostream& operator<<(ostream &out, FeetInches &obj);
        friend istream& operator>>(istream &in, FeetInches &obj);
        operator double();  
        operator int();
};

FeetInches::operator double()           // notice that there's no return type becaue it will always return double
{                                       //  
    double temp = feet;             
    temp += (inches/12.0);
    return temp;                        // returns the double version
}

FeetInches::operator int()           // notice that there's no return type becaue it will always return double
{                                       //  
    return feet;                        // returns the double version
}

ostream& operator<<(ostream &out, FeetInches &obj)
{
   out << obj.feet << " feet, " << obj.inches << " inches";
   return out;
}

istream& operator>>(istream &in, FeetInches &obj)
{
    cout << "Feet: ";
    in >> obj.feet;
    
    cout << "Inches: ";
    in >> obj.inches;
    
    obj.simplify();

    return in;
}

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

FeetInches FeetInches::operator--()
{
    --inches;
    simplify();
    return *this
}
FeetInches FeetInches::operator--(int)
{
    FeetInches temp(feet, inches);
    inches--;
    simplify();
    return temp;
}


int main()
{

    double d;   // double input
    int i;   // int input
    
    FeetInches distance;

    cout << "Enter a distance in feet and inches:\n";
    cin >> distance;

    // convert the distance object to a double
    d = distance;

    // convert the distance object to an int
    i = distance;

    cout << "The value " << distance;
    cout << " is equivalent to " << d << " feet\n";
    cout << "or " << i << " feet, rounded down.\n";




   return 0;
}

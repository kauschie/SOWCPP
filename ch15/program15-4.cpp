#include <iostream>
using namespace std;

class BaseClass
{
    public:
        BaseClass()     // constructor
        {
            cout << "This is the BaseClass constructor.\n";
        }

        ~BaseClass()    // destructor
        {
            cout << "This is the BaseClass destructor.\n";
        }
};

class DerivedClass : public BaseClass
{
    public:
        DerivedClass()
        {
            cout << "This is the DerivedClass constructor.\n";
        }
        ~DerivedClass()
        {
            cout << "This is the DerivedClass destructor.\n";
        }
};


int main()
{ 

    cout << "We will now define a DerivedClass object.\n";

    DerivedClass obj;

    cout << "The program is now going to end.\n";


    return 0;
}

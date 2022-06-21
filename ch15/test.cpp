#include <iostream>
using namespace std;


class Base
{
    private:                        // private members from base class stay private
        int x;                      // will only be available to the derived class if you use the base class's
    public:                         // member functions
        Base() { x = 0; }                   ///// Note: base constructors aren't inhereted
        Base(int n) { x = n; }
        void baseSetFunc(int n) { x = n; }   
        int getbaseVal() { return x; }
};

class Derived : public Base             // DeriedClassName : AccessSpecifier BaseClassName
{
    private:
        int y;                          
    public:
        Derived() { y = 0; }            // public functions/variables are available to the derived class
        Derived(int z) { y = z; }
        int getVal() { return y; }
};

int main()
{
    Derived d(5);
    Base b(4);

    d.baseSetFunc(10);          // works to set d.x = 10; 
    d.getVal();              // returns d.y which is 10
    
    cout << d.getVal() << endl;
    cout << d.getbaseVal() << endl;

    return 0;
}


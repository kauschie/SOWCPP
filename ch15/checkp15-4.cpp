// checkp 15-4
// private members are inaccessible to derived classes
// protected members may be accessed by the derived class
//
// checkp 15-5
// member access specification determines whether a class variable is accessible outside of the class.
// class access specification determins how the derived class inherits members of the base class
//
#include <iostream>
using namespace std;

class CheckPoint
{
    private:
        int a;
    protected:
        int b;
        int c;
        void setA(int x) { a = x; }
    public:
        void setB(int y) { b = y; }
        void setC(int z) { c = z; }
};

// checkp 15-6
// class Quiz : private CheckPoint
// a - inaccessible
// b - private
// c - private
// setA - private
// setB - private
// setC - private
//
// class Quiz : protected CheckPoint
// a - inaccessible
// b - protected
// c - protected
// setA - protected
// setB - protected
// setC - protected
//
// class Quiz : public CheckPoint
// a - inaccessible
// b - protected
// c - protected
// setA - protected
// setB - public
// setC - public
//
// class Quiz : CheckPoint          // declared as private by default

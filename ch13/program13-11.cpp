// This program demonstrates a constructor
#include <iostream>
using namespace std;

// class definitions
class Demo
{
    public:
        Demo();     // Constructor
        ~Demo();    // destructor
};

Demo::Demo()
{
    cout << "Welcome to the constructor!\n";
}

Demo::~Demo()
{
    cout << "The destructor is now running.\n";
}

int main()
{

    cout << "This runs before the object is made\n";
    Demo demoObject; // Define a Demo object

    cout << "This program demonstrates an object\n";
    cout << "with a constructor and a destructor.\n";

    return 0;
}

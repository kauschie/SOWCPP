#include <iostream>
using namespace std;

// Animal is a base class
class Animal
{
    public:
        Animal()
        { cout << "Animal constructor executing.\n"; }
        // destructor
        virtual ~Animal()
        { cout << "Animal destructor executing.\n"; }
};

// dog class is derived from animal
class Dog : public Animal
{
    public:
        // Constructor
        Dog() : Animal()
        { cout << "Dog constructor executing.\n"; }
        // Destructor
        ~Dog() 
        { cout << "Dog destructor executing.\n"; }
};

int main()
{
    // Create a dog object referenced by an animal pointer
    Animal *myAnimal = new Dog;

    // Delete the dog object
    delete myAnimal;

    return 0;
}
        

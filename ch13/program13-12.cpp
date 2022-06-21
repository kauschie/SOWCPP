#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class ContactInfo
{
    private:
        char *name;     // the name
        char *phone;    // the phone number
    public:
        // Constructor
        ContactInfo(char *n, char *p)
        {   // Allocate just enough memory for the name and phone number
            name = new char[strlen(n) + 1];
            phone = new char[strlen(p) + 1];

            // copy the name and phone number to the allocated memory.
            strcpy(name, n);
            strcpy(phone, p);   }

        // Destructor
        ~ContactInfo()
        {   delete [] name;
            delete [] phone;    }

        char *getName() const 
        { return name; }

        char *getPhoneNumber() const
        { return phone; }
};

int main()
{   // note: textbook attempts to intantiate entry like so:
    // ContactInfo entry("Kristen Lee", "555-2021") which is now an illegal statement post c++11
    // so the compiler will yell at you for passing a string literal as a pointer to a c string
    char name[] = "Kristen Lee";
    char num[] = "555-2021";
    ContactInfo entry(name, num);

    // Display the object's data.
    cout << setw(14) << "Name: " << entry.getName() << endl;
    cout << setw(14) << "Phone Number: " << entry.getPhoneNumber() << endl;
    
    return 0;
}

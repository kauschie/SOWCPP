// This program uses a structure variable to store a record to a file
#include <iostream>
#include <fstream>
using namespace std;

// ARRAY SIZES
const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

// declare a structure for the record
struct Info
{
    char name[NAME_SIZE];
    int age;
    char address1[ADDR_SIZE];
    char address2[ADDR_SIZE];
    char phone[PHONE_SIZE];
};

int main()
{
    Info person;    // to hold info about a person
    char again;     // Y or N

    // Open a file for binary output
    fstream people("people.dat", ios::out | ios::binary);

    do
    {
        // get data about a person.
        cout << "Enter the following data about a person:\n";
        cout << "Name: ";
        cin.getline(person.name, NAME_SIZE);
        cout << "Age: ";
        cin >> person.age;
        cin.ignore();   // SKIP over remaining newline
        cout << "Address line 1: ";
        cin.getline(person.address1, ADDR_SIZE);
        cout << "Address line 2: ";
        cin.getline(person.address2, ADDR_SIZE);
        cout << "Phone: ";
        cin.getline(person.phone, PHONE_SIZE);

        // WRITE THE CONTENTS of the person struct to the file.
        people.write(reinterpret_cast<char *>(&person), sizeof(person));

        // determin whether the user wants to write another record.
        cout << "Do you want to enter another record (y/n) ? ";
        cin >> again;
        cin.ignore();   // skip over remaining newline
    } while (again == 'Y' || again == 'y');
    
    people.close();

    return 0;
}

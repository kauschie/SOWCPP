// This program uses a structure variable to read a record to a file
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
    fstream people("people.dat", ios::in | ios::binary);

    // test for errors
    if (!people)
    {
        cout << "Error opening file. Program aborting.\n";
        return 0;
    }

    cout << "Here are the people int he file:\n\n";
    // read the first record from the file
    people.read(reinterpret_cast<char *>(&person), sizeof(person));

    // while not at the end of the file, display the records.
    while (!people.eof())
    {
        // display the record
        cout << "Name: " << person.name << endl;
        cout << "Age: " << person.age << endl;
        cout << "Address line 1: ";
        cout << person.address1 << endl;
        cout << "Address line 2: ";
        cout << person.address2 << endl;
        cout << "Phone: " << person.phone << endl;

        // wait for the user to press the enter key
        cout << "\nPress the enter key to see the next record.\n";
        cin.get(again);

        // read the next record from the file.
        people.read(reinterpret_cast<char *>(&person), sizeof(person));
    }

    cout << "That's all the data in the file!\n";
    people.close();
    return 0;
  
}

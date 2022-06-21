// this program randomly reads a record of data from a file
#include <iostream>
#include <fstream>
using namespace std;

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

// function prototypes
long byteNum(int);
void showRec(Info);

int main()
{
   Info person;     // to hold info about a person
   fstream people;  // file stream object

   // open the file for input in binary mode.
    people.open("people.dat", ios::in | ios::binary);

    // test for errors
    if (!people)
    {
        cout << "Could not open file.\n";
        return 0;
    }

    // read and display record 1 (the second record).
    cout << "Here is record 1:\n";
    people.seekg(byteNum(1), ios::beg);
    people.read(reinterpret_cast<char *>(&person), sizeof(person));
    showRec(person);

    // read and display record 0 (the first record).
    cout << "\nHere is record 0:\n";
    people.seekg(byteNum(0), ios::beg);
    people.read(reinterpret_cast<char *>(&person), sizeof(person));
    showRec(person);

    // close the file
    people.close();
    return 0;
}

long byteNum(int recNum)
{
    return sizeof(Info) * recNum;
}

void showRec(Info record)
{
    cout << "Name: " << record.name << endl;
    cout << "Age: " << record.age << endl;
    cout << "Address line 1: " << record.address1 << endl; 
    cout << "Address line 2: " << record.address2 << endl; 
    cout << "Phone: " << record.phone << endl;
}

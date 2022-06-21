// This program uses nested structures
#include <iostream>
#include <string>
using namespace std;

// The Date structure holds data about a date
struct Date
{
    int month;
    int day;
    int year;
};

// The place structure holds a physical address
struct Place
{
    string address;
    string city;
    string state;
    string zip;
};

// This EmployeeInfo struct holds an employee's data
struct EmployeeInfo
{   
    string name;
    int employeeNumber;
    Date birthDate;     // Nested structure
    Place residence;    // Nested structure
};

int main()
{
    // define a struct variable to hold info about the manager
    EmployeeInfo manager;
    // get the managers name and employee number:
    cout << "Enter the manager's name: ";
    getline(cin, manager.name);
    cout << "Enter the manager's employee number: ";
    cin >> manager.employeeNumber;

    // Get the manager's birth date
    cout << "Now enter the manager's date of birth.\n";
    cout << "Month (up to 2 digits): ";
    cin >> manager.birthDate.month;
    cout << "Day (up to 2 digits): ";
    cin >> manager.birthDate.day;
    cout << "Year: ";
    cin >> manager.birthDate.year;
    cin.ignore();       // skip the remaining newline character

    // Get the manager's residence information
    cout << "Enter the manager's street address: ";
    getline(cin, manager.residence.address);
    cout << "City: ";
    getline(cin, manager.residence.city);
    cout << "State: ";
    getline(cin, manager.residence.state);
    cout << "Zip: ";
    getline(cin, manager.residence.zip);


    // display all the info
    cout << "\nHere is the manager's information:\n";
    cout << manager.name << endl;
    cout << "Employee Number: " << manager.employeeNumber << endl;
    cout << "Date of Birth: ";
    cout << manager.birthDate.month << "-";
    cout << manager.birthDate.day << "-";
    cout << manager.birthDate.year << endl;
    cout << "Place of residence:\n";
    cout << manager.residence.address << endl;
    cout << manager.residence.city << ", ";
    cout << manager.residence.state << " ";
    cout << manager.residence.zip << endl;
    

    return 0;
}

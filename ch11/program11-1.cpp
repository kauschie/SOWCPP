// This program demonstrates the use of structures.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct PayRoll
{
    int empNumber;      // Employee number
    string name;        // Employee's name
    double hours;       // hours worked
    double payRate;     // hourly payRate
    double grossPay;    // Gross Pay
};

int main()
{

    PayRoll employee;   // employee is a PayRoll Structure
    
    // get the emp number
    cout << "Enter the employees number: ";
    cin >> employee.empNumber;

    // Get the employee's name
    cout << "Enter the employees name: ";
    cin.ignore();               // to skip the /n character
    getline(cin, employee.name);

    // get hours worked
    cout << "Enter hours worked: ";
    cin >> employee.hours;

    // get the employee's hourly pay rate
    cout << "What is the employee's hourly pay rate? ";
    cin >> employee.payRate;

    // Calculate the employee's gross pay
    employee.grossPay = employee.payRate * employee.hours;

    // display the employee data.
    cout << "Here is the employee's payroll data:\n";
    cout << "Name: " << employee.name << endl;
    cout << "Number: " << employee.empNumber << endl;
    cout << "Hours worked: " << employee.hours << endl;
    cout << "Hourly payRate: " << employee.payRate << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Gross Pay: " << employee.grossPay << endl;

    return 0;
}

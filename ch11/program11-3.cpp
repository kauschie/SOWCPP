// This program demonstrates partially initialized structures.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct EmployeePay
{
    string name;        // Employee's name
    int empNum;         // Employee number
    double payRate;     // hourly payRate
    double hours;       // hours worked
    double grossPay;    // Gross Pay
};

int main()
{



    EmployeePay employee1 = {"Betty Ross", 141, 18.75};
    EmployeePay employee2 = {"Jill Sandburg", 142, 17.50};

    // Calculate the pay for employee1
    cout << "Name: " << employee1.name << endl;
    cout << "Employee Number: " << employee1.empNum << endl;
    cout << "Enter "<< employee1.name << "'s hours worked: ";
    cin >> employee1.hours;
    employee1.grossPay = employee1.payRate * employee1.hours;
    cout << "Gross Pay: " << employee1.grossPay << endl;


    // Calculate the pay for employee2
    cout << "Name: " << employee2.name << endl;
    cout << "Employee Number: " << employee2.empNum << endl;
    cout << "Enter "<< employee2.name << "'s hours worked: ";
    cin >> employee2.hours;
    employee2.grossPay = employee2.payRate * employee2.hours;


    // get the emp number
    cout << "Enter the employees number: ";
    cin >> employee.empNumber;

    // Get the employee's name
    // get hours worked

    // get the employee's hourly pay rate
    cout << "What is the employee's hourly pay rate? ";
    cin >> employee.payRate;

    // Calculate the employee's gross pay

    // display the employee data.
    cout << "Here is the employee's payroll data:\n";
    cout << "Name: " << employee.name << endl;
    cout << "Number: " << employee.empNumber << endl;
    cout << "Hours worked: " << employee.hours << endl;
    cout << "Hourly payRate: " << employee.payRate << endl;
    cout << fixed << showpoint << setprecision(2);

    return 0;
}

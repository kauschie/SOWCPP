// This program demonstrates a function that uses a
// pointer to a structure variable as a parameter
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{   
    string name;        // student's name
    int idNum;          // student ID number
    int creditHours;    // credit hours enrolled
    double gpa;         // current GPA
};

void getData(Student *s);    // function prototype

int main()
{
    Student freshman;

    // Get the student data.
    cout << "Enter the following student data:\n";
    getData(&freshman);     // pass the address of the freshman.
    cout << "\nHere is the student data you entered:\n";

    // Now display the data stored in freshman
    // shows that the pointer was used

    cout << setprecision(3);
    cout << "Name: " << freshman.name << endl;
    cout << "ID Number: " << freshman.idNum << endl;
    cout << "Credit Hours: " << freshman.creditHours << endl;
    cout << "GPA: " << freshman.gpa << endl;

    return 0;
}

void getData(Student *s)    // function prototype
{
   // get student name.
   cout << "Student name: ";
   getline(cin, s->name);       // when derefrencing the pointer struct, use the -> structure pointer operator

   // Get the student ID num
   cout << "Student ID Number: ";
   cin >> s->idNum;

   // Get the credit hours enrolled.
   cout << "Credit hours enrolled: ";
   cin >> s->creditHours;

   // Get the GPA
   cout << "Current GPA: ";
   cin >> s->gpa;

}

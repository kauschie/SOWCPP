// This program demonstrates overloaded functions to calculate
// the gross weekly pay of hourly paid or salaried employees.
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getChoice(char &);
double calcWeeklyPay(int, double);
double calcWeeklyPay(double);

int main()
{
    char selection;     // menu selection
    int worked;         // Hours worked
    double rate,        // Hourly pay rate
           yearly;      // yearly salary

    // set numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    // Display the menu and get a selection.
    cout << "Do you want to calculate the weekly pay of\n";
    cout << "(H) an hourly paid employee, or\n";
    cout << "(S) a salaried employee?\n";
    getChoice(selection);

    // Process the menu selection.
    switch (selection)
    {
        // Hourly paid employee
        case 'H':
        case 'h': cout << "How many hours were worked? ";
                  cin >> worked;
                  cout << "What is the hourly pay rate? ";
                  cin >> rate;
                  cout << "The gross weekly pay is $";
                  cout << calcWeeklyPay(worked, rate) << endl;
                  break;
        // Salaried employee
        case 'S':
        case 's': cout << "What is the annual salary? ";
                  cin >> yearly;
                  cout << "The gross weekly pay is $";
                  cout << calcWeeklyPay(yearly) << endl;
                  break;
    }
    return 0;
}

void getChoice(char &letter)
{
    // get the users selection
    cout << "Enter your choice (H or S): ";
    cin >> letter;

    // validate the selection.
    while (letter != 'H' && letter != 'h' &&
            letter != 'S' && letter != 's')
    {
        cout << "Please enter H or S: ";
        cin >> letter;
    }

}

double calcWeeklyPay(int hours, double payRate)
{
    return hours * payRate;
}

double calcWeeklyPay(double annSalary)
{
    return annSalary / 52;
}


// using switch for a menu system
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int choice;     // to hold the menu choice
    int months;     // to hold the number of months
    double charges; // to hold the monthly charges

    // Constants for membership rates
    const double ADULT = 40.0,
                CHILD = 20.0,
                SENIOR = 30.0;

    // Constants for menu choices
    const int ADULT_CHOICE = 1,
          CHILD_CHOICE = 2,
          SENIOR_CHOICE = 3,
          QUIT_CHOICE = 4;

    // Display the menu and get a choice.
    cout << "   Health Club Membership Menu\n\n"
        << "1.  Standard Adult Membership\n"
        << "2.  Child Membership\n"
        << "3.  Senior Membership\n"
        << "4.  Quit the Program\n\n"
        << "Enter your choice: ";
    cin >> choice;

    if (choice != 4)
    {
        cout << "For how many months? ";
        cin >> months;
        switch (choice)
        {
            case 1: charges = months * ADULT;
                    break;
            case 2: charges = months * CHILD;
                    break;
            case 3: charges = months * SENIOR;
                    break;
            default: cout << "The valid choices are 1 through 4. Run the\n"
                     << "program again and select one of those.\n";
                    exit(0);      
        }
        cout << "The total charges are $" << charges << endl;
    }
    else
        cout << "Program ending....\n";
    
    return 0;
}


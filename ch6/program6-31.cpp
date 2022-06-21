// This program will assist the high adventure travel agency
// in calculating the costs of their 4 major vacation package
#include <iostream>
#include <iomanip>
using namespace std;

// Global Constants for the charges.
const double CLIMB_RATE = 350.0;            // Base rate - Devil's Courthouse
const double SCUBA_RATE = 1000.0;           // Base rate - Bahamas
const double SKY_DIVE_RATE = 400.0;         // Base rate - Sky diving
const double CAVE_RATE = 700.0;             // Base rate - Spelunking
const double CLIMB_INSTRUCT = 100.0;        // Climbing Instruction
const double SCUBA_INSTRUCT = 100.0;        // Scuba Instruction
const double DAILY_CAMP_RENTAL = 40.0;      // Daily camping equipment rental
const double DAY_LODGE_1 = 65.0;            // Lodging option (sky diving)
const double DAY_LODGE_2 = 120.0;           // Lodging option (sky diving)

// Function prototypes
void climbing();
void scuba();
void skyDive();
void spelunk();
int menu();

int main()
{
   int selection;

   cout << fixed << showpoint << setprecision(2);
   do
   {
        selection = menu();
        switch(selection)
        {
            case 1 : climbing();
                     break;
            case 2 : scuba();
                     break;
            case 3 : skyDive();
                     break;
            case 4 : spelunk();
                     break;
            case 5 : cout << "Exiting program.\n\n";
                     break;
        }
   }while(selection != 5);
   return 0;
}

//*******************************************************
//  definition of       menu()                          *
//  displays the main menu and asks the user to select  *
//  an option. Returns an integer in the range 1 - 5.   *
//*******************************************************

int menu()
{
    int choice;

    cout << "High adventure Travel Agency\n";
    cout << "-------------------------------\n";
    cout << "1) Devil's Courthouse Adventure Weekend\n";
    cout << "2) Scuba Bahama\n";
    cout << "3) Sky Dive Colorado\n";
    cout << "4) Barron Cliff Spelunk\n";
    cout << "5) Exit Program\n\n";
    cout << "Enter 1,2,3,4, or 5: ";
    cin >> choice;
    while (choice < 1 || choice > 5)
    {
        cout << "Invalid Selection. Enter 1, 2, 3, 4, or 5: ";
        cin >> choice;
    }
    return choice;
}


//*******************************************************
//  definition of       climbing()                      *
//  This function calculates the charges for the        *
//  Devil's Courthouse Adventure Weekend package        * 
//*******************************************************
//
void climbing()
{
    int beginners,  // Those needing instruction
        advanced,   // Those not needing instruction
        needEquip;  // Those renting camping equipment
    double baseCharges, // Base charges
           charges,     // Total charges
           instruction, // Cost of instruction
           equipment,   // Cost of equipment rental
           discount = 0,    // Discount
           deposit;     // Required deposit

    cout << "\nDevil's Courthouse Adventure Weekend\n";
    cout << "---------------------------------------\n";
    cout << "How many will be going who need an instructor? ";
    cin >> beginners;
    cout << "How many advanced climbers will be going? ";
    cin >> advanced;
    cout << "How many will rent camping equipment? ";
    cin >> needEquip;
    // calculate base charges.
    baseCharges = (beginners + advanced) * CLIMB_RATE;
    charges = baseCharges;
    
    // calculate 10% discount for 5 or more.
    if ((beginners + advanced) > 4)
    {
        discount = (charges * .1);
        charges -= discount;
    }

    // Add cost of instruction.
    instruction = beginners * CLIMB_INSTRUCT;
    charges += instruction;

    // Add cost of camping equipment rental
    equipment = needEquip * DAILY_CAMP_RENTAL * 4;
    charges += equipment;

    // Calculate required deposit.
    deposit = charges / 2.0;

    cout << "Number in party: " << (beginners + advanced) << endl
        << "Base charges: $" << baseCharges << endl
        << "Instruction cost: $" << instruction << endl
        << "Equipment Rental: $" << equipment << endl
        << "Discount: $" << discount << endl
        << "Total Charges: $" << charges << endl
        << "Required Deposit: $" << deposit << endl << endl;
}

//*******************************************************
//  definition of       scuba()                         *
//  This function calculates the charges for the        *
//  Scuba Bahama Package
//*******************************************************

void scuba()
{
    int beginners,  // Those needing instruction
        advanced;   // Those not needing instruction
    double baseCharges, // Base charges
           charges,     // Total charges
           instruction, // Cost of instruction
           discount = 0,    // Discount
           deposit;     // Required deposit

    cout << "\nScuba Bahama\n";
    cout << "---------------------------------------\n";
    cout << "How many will be going who need an instructor? ";
    cin >> beginners;
    cout << "How many advanced scuba divers will be going? ";
    cin >> advanced;
    
    // Calculate base charges

    baseCharges = (beginners + advanced) * SCUBA_RATE;
    charges = baseCharges;

    // Calculate 10% discount for 5 or more

    if ((beginners + advanced) > 4)
    {
        discount = (charges * .1);
        charges -= discount;
    }

    // Add cost of instruction 
    instruction = beginners * SCUBA_INSTRUCT;
    charges += instruction;

    // Calculate required deposit.
    deposit = charges / 2.0;
 
    cout << "Number in party: " << (beginners + advanced) << endl
        << "Base charges: $" << baseCharges << endl
        << "Instruction cost: $" << instruction << endl
        << "Discount: $" << discount << endl
        << "Total Charges: $" << charges << endl
        << "Required Deposit: $" << deposit << endl << endl;
}


//*******************************************************
//  definition of       skyDive()                       *
//  This function calculates the charges for the        *
//  Sky Dive Colorado Package                           *
//*******************************************************

void skyDive()
{
    int party,          // Number in party
        lodge1,         // Number at first lodging choice
        lodge2;         // Number at second lodging choice

    double baseCharges,     // Base charges
           charges,         // Total charges
           discount = 0,    // discount
           lodging,         // cost of lodging
           deposit;         // required deposit

    cout << "\nSky Dive Colorado\n"
        << "--------------------------------------\n"
        << "How many will be going? ";
    cin >> party;
    
    // Calculate base charges.
    
    baseCharges = party * SKY_DIVE_RATE;
    charges = baseCharges;
    
    // Calculate 10% discount for 5 or more.

    if (party > 4)
    {
        discount = (charges * .1);
        charges -= discount;
    }

    // Calculate lodging costs
    cout << "How many will stay at Wilderness Lodge? ";
    cin >> lodge1;
    cout << "How many will stay at Luxury Inn? ";
    cin >> lodge2;
    lodging = (lodge1 * DAY_LODGE_1) + (lodge2 * DAY_LODGE_2);
    charges += lodging;

    // Calculate required deposit.
    deposit = charges / 2.0;
    cout << "Number in party: " << party << endl
        << "Base charges: $" << baseCharges << endl
        << "Lodging: $" << lodging << endl
        << "Discount: $" << discount << endl
        << "Total Charges: $" << charges << endl
        << "Required Deposit: $" << deposit << endl << endl;
}

    
//*******************************************************
//  definition of      spelunk()                        *
//  This function calculates the charges for the        *
//  Barron Cliff Spelunk package.                       * 
//*******************************************************
//
void spelunk()
{
    int party,      // Number in party 
        needEquip;  // Those renting camping equipment
    double baseCharges, // Base charges
           charges,     // Total charges
           equipment,   // Cost of equipment rental
           discount = 0,    // Discount
           deposit;     // Required deposit

    cout << "\nBarron Cliff Spelunk Weekend\n";
    cout << "------------------------------------\n";
    cout << "How many will be going? ";
    cin >> party;
    cout << "How many will rent camping equipment? ";
    cin >> needEquip;

    // calculate base charges.
    baseCharges = (party) * CAVE_RATE;
    charges = baseCharges;

    // calculate 10% discount for 5 or more
    if (party > 4)
    {
        discount = charges * 0.1;
        charges -= discount;
    }

    // Add cost of camping equipment rental
    equipment = needEquip * DAILY_CAMP_RENTAL * 4;
    charges += equipment;

    // calculate required deposit
    deposit = charges / 2.0;
    cout << "Number in party: " << party << endl
        << "Base charges: $" << baseCharges << endl
        << "Equipment Rental: $" << equipment << endl
        << "Discount: $" << discount << endl
        << "Total Charges: $" << charges << endl
        << "Required Deposit: $" << deposit << endl << endl;
}


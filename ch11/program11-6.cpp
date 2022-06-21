// this program has functions that accept structure variables as args
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct InventoryItem
{   
    int partNum;        // part num
    string description; // int description
    int onHand;         // units on hand
    double price;       // unit price
};

// function prototypes
void getItem(InventoryItem &p);  // arg passed by reference
void showItem(InventoryItem item);  // arg passed by value

int main()
{
    
    InventoryItem part;

    getItem(part);
    showItem(part);

    return 0;
}


void getItem(InventoryItem &p)
{
    // get the part number
    cout << "Enter the part number: ";
    cin >> p.partNum;

    // get the part description
    cout << "Enter the part description: ";
    cin.ignore();   // ignore the remaining newline character
    getline(cin, p.description);

    // Get the quantity on hand.
    cout << "Enter the quantity on hand: ";
    cin >> p.onHand;

    // Get the unit price.
    cout << "Enter the unit price: ";
    cin >> p.price;
}

void showItem(InventoryItem p)  // arg passed by value
{
    cout << fixed << showpoint << setprecision(2);
    cout << "Part Number: " << p.partNum << endl;
    cout << "Description: " << p.description << endl;
    cout << "Units On Hand: " << p.onHand << endl;
    cout << "Price: " << p.price << endl;
}

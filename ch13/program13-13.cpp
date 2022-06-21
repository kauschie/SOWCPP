// This program uses overloaded functions
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class InventoryItem
{
    private:
        string description;
        double cost;
        int units;
    public:
        // Constructor #1 (default constructor)
        InventoryItem()
        {   // initialize description, cost and units.
            description = "";
            cost = 0.0;
            units = 0;  }

        // Constructor #2
        InventoryItem(string desc)
        {   // assign value to description and initialize cost and units
            description = desc;
            cost = 0.0;
            units = 0;  }

        InventoryItem(string desc, double c, int u)
        {   // assign values to description cost and units
            description = desc;
            cost = c;
            units = u;  }

        // Mutators
        void setDescription(string d) { description = d; }
        void setCost(double c) { cost = c; }
        void setUnits(int u) { units = u; }
        
        // Accessors
        string getDescription() { return description; }
        double getCost() { return cost; }
        int getUnits() { return units; }
};

void showContact(InventoryItem item)
{
    cout << "Description: " << item.getDescription() << endl;
    cout << "Cost: " << item.getCost() << endl;
    cout << "Units on Hand: " << item.getUnits() << endl << endl;
}

int main()
{
    // create an InventoryItem using constructor #1
    InventoryItem item1;
    item1.setDescription("Hammer");
    item1.setCost(6.95);
    item1.setUnits(12);

    // create an InventoryItem using constructur #2
    InventoryItem item2("Pliers");

    // create an InventoryItem using constructur #2
    InventoryItem item3("Wrench", 8.75, 20);

    
    // display the data for items 1, 2 and 3
    showContact(item1);
    showContact(item2);
    showContact(item3);

    return 0;
}

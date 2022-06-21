// this program displays the contents of the inventory file
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int DESC_SIZE = 31;   // Description size

struct InventoryItem
{
    char desc[DESC_SIZE];
    int qty;
    double price;
};

int main()
{
    InventoryItem record;   // to hold an inventory record

    // open the file for binary input
    fstream inventory("Inventory.dat", ios::in | ios::binary);

    do
    {
        inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
        cout << "Description: " << record.desc << endl;
        cout << "Quantity: " << record.qty << endl;
        cout << "Price: " << fixed << setprecision(1) << record.price << endl;
    } while (!inventory.eof());

    // close the file
    inventory.close();

    return 0;
}

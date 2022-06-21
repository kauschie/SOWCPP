#include <iostream>
#include <iomanip>
using namespace std;

class Sale
{
    private:
        double itemCost, taxRate;
    public:
        Sale(double cost, double rate = 0.05)
        {  itemCost = cost;
            taxRate = rate; }

        double getItemCost() { return itemCost; }
        double getTaxRate() { return taxRate; }
        double getTax() const { return (itemCost * taxRate); }
        double getTotal() const { return (itemCost + getTax()); }
};

int main()
{
    double cost;

    cout << "Enter the cost of the item: ";
    cin >> cost;

    Sale itemSale(cost);

    cout << fixed << showpoint << setprecision(2);

    cout << "The amount of sales tax is $"
        << itemSale.getTax() << endl;
    cout << "The total of the sale is $"
        << itemSale.getTotal() << endl;
    return 0;

}

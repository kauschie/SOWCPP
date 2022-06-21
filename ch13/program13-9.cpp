#include <iostream>
#include <iomanip>
using namespace std;

class Sale
{
    private:
        double itemCost, taxRate;
    public:
        Sale(double cost, double rate)
        {  itemCost = cost;
            taxRate = rate; }

        double getItemCost() { return itemCost; }
        double getTaxRate() { return taxRate; }
        double getTax() const { return (itemCost * taxRate); }
        double getTotal() const { return (itemCost + getTax()); }
};

int main()
{
    const double TAX_RATE = 0.06;
    double cost;

    cout << "Enter the cost of the item: ";
    cin >> cost;

    Sale itemSale(cost, TAX_RATE);

    cout << fixed << showpoint << setprecision(2);

    cout << "The amount of sales tax is $"
        << itemSale.getTax() << endl;
    cout << "The total of the sale is $"
        << itemSale.getTotal() << endl;
    return 0;

}

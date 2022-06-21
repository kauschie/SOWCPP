#include <iostream>
#include <iomanip>
using namespace std;

// prototypes
void calcSales(const int units_sold[], const double unit_price[], double prod_sales[], int size);
void showOrder(const double prod_sales[], const int prod_id[], int units_sold[], double unit_price[], int size);
void multiSort(int prod_id[], double prod_sales[], int units_sold[], double prices[], int size);
void showTotals(const double prod_sales[], const int units_sold[], int size);
void swap(double & a, double & b);
void swap(int & a, int & b);

int main()
{
    // number of products company produces
    const int NUM_PRODS = 9;

    // Array with product ID numbers
    int id[NUM_PRODS] = { 914, 915, 916, 917, 918,
                            919, 920, 921, 922 };

    // Array with number of units sold for each product
    int units[NUM_PRODS] = { 842, 416, 127, 514, 437,
                                269, 97, 492, 212 };

    // Array with product prices
    double prices[NUM_PRODS] = { 12.95, 14.95, 18.95, 16.95, 21.95,
                              31.95, 14.95, 14.95, 16.96 };
    
    // Array to hold the computer sales amounts
    double sales[NUM_PRODS];

    // Calculate each product's sales.
    calcSales(units, prices, sales, NUM_PRODS);

    // sort the elements int he sales array in descending 
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel
    multiSort(id, sales, units, prices, NUM_PRODS);

    // set the numeric output formatting
    cout << fixed << showpoint << setprecision(2);

    // Display the products and sales amounts.
    showOrder(sales, id, units, prices, NUM_PRODS);

    // Display total units sold and total sales.
    showTotals(sales, units, NUM_PRODS);


    return 0;
}

void calcSales(const int units_sold[], const double unit_price[], double prod_sales[], int size)
{
    for (int index = 0; index < size; index++)
        prod_sales[index] = units_sold[index] * unit_price[index];
}

void showOrder(const double prod_sales[], const int prod_id[], int units_sold[], double unit_price[], int size)
{
    cout << "Product Number\tSales\tUnits Sold\tPrice\n";
    cout << "-----------------------------\n";
    for (int index = 0; index < size; index++)
    {
        cout << prod_id[index] << "\t\t$";
        cout << setw(8) << prod_sales[index] << "\t" 
            << setw(5) << units_sold[index] << "\t"
            << setw(5) << unit_price[index] << endl;
    }
    cout << endl;
}

void multiSort(int prod_id[], double prod_sales[], int units_sold[], double prices[], int size)
{
    int maxIndex;
    double maxValue;
    for (int start = 0; start < size -1; start++)
    {
        maxIndex = start;
        maxValue = prod_sales[start];
        for (int i = start+1; i < size; i++)
        {
            if (prod_sales[i] > maxValue)
            {
                maxIndex = i;
                maxValue = prod_sales[i];
            }
        }
        swap(prod_id[maxIndex], prod_id[start]);
        swap(prod_sales[maxIndex], prod_sales[start]);
        swap(units_sold[maxIndex], units_sold[start]);
        swap(prices[maxIndex], prices[start]);
    }
}

void showTotals(const double prod_sales[], const int units_sold[], int size)
{
    int totalUnits = 0;
    int totalSales = 0.0;

    for (int index = 0; index < size; index++)
    {
        totalUnits += units_sold[index];
        totalSales += prod_sales[index];
    }
    
    cout << "Total Units Sold: " << totalUnits << endl;
    cout << "Total sales: $" << totalSales << endl;
}

void swap(double & a, double & b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


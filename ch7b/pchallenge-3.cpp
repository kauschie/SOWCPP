// Chapter 7 Programming Challenge 3
// 10/14/21
// mike kausch
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void get_sales(int sales[], string type[], int size);
int get_total(int sales[], int size);
int get_highest(int sales[], int size);
int get_lowest(int sales[], int size);

int main()
{
    const int ARRSIZE = 5;
    const double PRICE = 3.45;
    
    string salsa_types[ARRSIZE] = {"mild", "medium", "sweet", "hot", "zesty"};
    int jars_sold[ARRSIZE];
    
    double total_sales = 0;

    int total_jars = 0,
        highest_id,
        lowest_id;

    cout << "Welcome to the Zippy Chips and Sally's Salsa Financial Calculator\n";
    get_sales(jars_sold, salsa_types, ARRSIZE);
    total_sales = get_total(jars_sold, ARRSIZE);
    highest_id = get_highest(jars_sold, ARRSIZE);
    lowest_id = get_lowest(jars_sold, ARRSIZE);
   
    cout << fixed << showpoint << setprecision(2) << endl << endl;
    cout << "Sales for :\n";
    for (int i = 0; i < ARRSIZE; i++)
    {   
        cout << salsa_types[i] << " sold " << jars_sold[i]
            << " jars for: $" << jars_sold[i]*PRICE << endl;
    }

    cout << "\nThe total amount of jars sold were " << total_sales
        << " for: $" << total_sales*PRICE << endl << endl;
    cout << "The jar that the most was " << salsa_types[highest_id] << endl
        << "with  " << jars_sold[highest_id] << "  jars sold for: $" << jars_sold[highest_id]*PRICE;
    cout << "\nThe jar that sold the least was " << salsa_types[lowest_id] << endl
        << "with  " << jars_sold[lowest_id] << "  jars sold for: $" << jars_sold[lowest_id]*PRICE << endl;

    return 0;   
}

int get_highest(int sales[], int size)
{
    int highest = 0;
    for (int i = 1; i < size; i++)
        highest = (sales[i] > sales[highest]) ? i : highest;
    return highest;
}

int get_lowest(int sales[], int size)
{
    int lowest = 0;
    for (int i = 1; i < size; i++)
        lowest = (sales[i] < sales[lowest]) ? i : lowest;
    return lowest;
}

void get_sales(int sales[], string type[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the sales for " << type[i] << ": ";
        do
        {
            cin >> sales[i];
        } while (sales[i] < 0);
    }
}

int get_total(int sales[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += sales[i];
    return sum;
}


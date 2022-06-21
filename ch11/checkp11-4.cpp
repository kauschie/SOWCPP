#include <iostream>
using namespace std;

struct Product
{
    string description;     // product description
    int partNum;            // part number
    double cost;            // Product cost
};

// checkp 11.8
struct Measurement
{
    int miles;
    long int meters;
};

// checkp 11.9
struct Destination
{
    string city;
    Measurement distance;
};

int main()
{
    //
    //  **** START HERE *****
    //
    // checkpoint 11.4
    Product productList[100];

    // checkpoint 11.5
    for (int i = 0; i < 20; i++)
    {
        productList[i].description = "";
        productList[i].partNum = 0;
        productList[i].cost = 0.0;
    }

    // checkp 11.6
    productlist[0].description = "Claw hammer";
    productlist[0].partNum = 547;
    productlist[0].cost = 8.29;

    // checkp 11.7
    for (int i = 0; i < 20; i++)
    {
        cout << productList[i].description << endl; 
        cout << productList[i].partNum << endl;
        cout << productList[i].cost << endl << endl;
    }


    // checkp 11.9 continued
    Destination vacation;

    // checkp 11.10
    vacation.city = "Tupelo";
    vacation.distance.miles = 375;
    vacation.distance.meters = 603375;

    
    

    return 0;
}

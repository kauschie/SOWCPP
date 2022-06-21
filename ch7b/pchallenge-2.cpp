// Chapter 7 Programming Challenge 2
// 10/14/21
// mike kausch
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void get_rain(double rain_monthly[], string monthArr[], int ArrSize);
int get_highest(double rain_monthly[], int ArrSize);
int get_lowest(double rain_monthly[], int ArrSize);
double get_total(double rain_monthly[], int ArrSize);

int main()
{
    string months[12] = {"January", "February", "March", "April", "May", 
        "June", "July", "August", "September", 
        "October", "November", "December"};
    double rain[12];
    get_rain(rain, months, 12);
    int highest = get_highest(rain, 12);
    int lowest = get_lowest(rain, 12);
    double total = get_total(rain, 12);

    cout << fixed << showpoint << setprecision(2) << endl << endl;
    cout << "The total rainfall for the year is " << total << " mL.\n";
    cout << "The average monthly rainfall is " << total/12 << " ml.\n";
    cout << months[highest] << " had the highest rainfall with " << rain[highest] << " mL.\n";
    cout << months[lowest] << " had the lowest rainfall with " << rain[lowest] << " ml.\n";

    return 0;
}

void get_rain(double rain_monthly[], string monthArr[], int ArrSize)
{
    cout << "~~This program calculates annual rainfall~~\n";
    for (int i = 0; i < ArrSize; i++)
    {
        do
        {
            cout << "Enter the amount of rain for " << monthArr[i] << ": ";
            cin >> rain_monthly[i];
            if (rain_monthly[i] < 0)
                cout << "Amounts must be non negative\n";
        } while (rain_monthly[i] < 0);
    }
}

int get_highest(double rain_monthly[], int ArrSize)
{
    int highest = 0;
    for (int i = 1; i < ArrSize; i++)
    {   
        if (rain_monthly[i] > rain_monthly[highest])
            highest = i;
    }
    return highest;
}

int get_lowest(double rain_monthly[], int ArrSize)
{
    int lowest = 0;
    for (int i = 1; i < ArrSize; i++)
    {   
        if (rain_monthly[i] < rain_monthly[lowest])
            lowest = i;
    }
    return lowest;
}

double get_total(double rain_monthly[], int ArrSize)
{
    double sum = 0;
    for (int i = 0; i < ArrSize; i++)
        sum += rain_monthly[i];
    return sum;
}


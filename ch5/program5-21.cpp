// This program reads data from a file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outputFile;    // File stream object
    int numberOfDays;   // number of days of sales
    double sales;       // sales amount for a day

    // Get the number of days.
    cout << "For how many days did you have sales? ";
    cin >> numberOfDays;

    // Open a file names Sales.txt
    outputFile.open("Sales.txt");
        // Get the sales for the day
    for (int i = 1; i <= numberOfDays; i++)
    {
        cout << "Enter the sales for day " << i << ": ";
        cin >> sales;

        // Write the sale figure to the file
        outputFile << sales << endl;

    }
    // close the file
    outputFile.close();
    cout << "Data written to Sales.txt\n";

    return 0;
}


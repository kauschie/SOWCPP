// This program converts the speeds 60 kph through 
// 130 kph (in 10kph increments) to mph
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Constants for the speeds
    const int START_KPH = 60,
              END_KPH = 130;

    // Constant for the converstion factor
    const double CONVERSION_FACTOR = 0.6214;

    // Variables
    int kph;        // to hold speeds in kph
    double mph;         // to hold speeds in mph

    // set the text formatting
    cout << fixed << showpoint << setprecision(1);

    // display the table headings
    cout << "KPH\tMPH\n";
    cout << "------------\n";

    // Display the speeds
    for (kph = START_KPH; kph <= END_KPH; kph+=10)
    {
        mph = kph * CONVERSION_FACTOR;
        cout << kph << "\t" << mph << endl;
    }
    
    return 0;
}


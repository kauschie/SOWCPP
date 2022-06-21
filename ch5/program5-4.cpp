// This program assists a technician in the process
// of checking a stubstance's temperature.
#include <iostream>
using namespace std;

int main()
{
    const double MAX_TEMP = 102.5;  // Maximum temperature
    double temperature;

    // Get the current temperature
    cout << "Enter the substance's temperature (C): ";
    cin >> temperature;

    
    // As long as necessary instruct the technician
    // to adjust the temperature.
    while (temperature > MAX_TEMP)
    {
        cout << "The temperature is too high. Turn the\n"
            << "thermostat down and wait 5 minutes.\n"
            << "Then take the temperature (C) again\n"
            << "and enter it here: ";
        cin >> temperature;
    }

    // Remintd the technician to check the temperature
    // again in 15 minutes.
    cout << "The temperature is acceptable.\n";
    cout << "Check it again in 15 minutes.\n";

    return 0;
}

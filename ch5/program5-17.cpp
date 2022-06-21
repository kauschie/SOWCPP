// This program writes user input to a file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outputFile;
    int number1, number2, number3;

    // Open an output file
    outputFile.open("Numbers.txt");

    // Get three numbers from the user.
    cout << "Enter a number: ";
    cin >> number1;
    cout << "Enter another number: ";
    cin >> number2;
    cout << "One more time. Enter a number: ";
    cin >> number3;

    // Write the numbers to a file
    outputFile << number1 << endl << number2
        << endl << number3 << endl;

    // Close the file
    outputFile.close();
    cout << "Done.\n";

    return 0;
}


// This program tests for file open errors
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    int number;

    // Open the file
    inputFile.open("BadListOfNumbers.txt");

    // read numbers from the file and display them
    if (inputFile)
    {
        while ( inputFile >> number )
            cout << number << endl;

        inputFile.close();
    }   
    else
    {
        // Display an error message
        cout << "Error opening the file.\n";
    }

    return 0;
}


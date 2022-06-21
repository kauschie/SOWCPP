// This program tests for file open errors
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile;
    string filename;
    int number;

    // Get the file name
    cout << "Enter the filename: ";
    cin >> filename;
      

    // Open the file
    inputFile.open(filename);

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


// This program writes the contents of an array to a file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;      // array size
    int numbers[ARRAY_SIZE];        // array with 10 elements
    int count;                      // loop counter variable
    ofstream outputFile;            // Output file stream object

    // Store values int hearray
    for (count = 0; count < ARRAY_SIZE; count++)
        numbers[count] = count;

    // Open file for output
    outputFile.open("SavedNumbers.txt");

    // write the array contents to the file
    for (count = 0; count < ARRAY_SIZE; count++)
        outputFile << numbers[count] << endl;

    // close the file
    outputFile.close();

    // that's it!
    cout << "The numbers were saved to the file.\n";

    return 0;
}

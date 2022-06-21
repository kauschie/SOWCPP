// This program writes data toa  file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Opening the file
    ofstream outputFile;            // creates outputFile object
    outputFile.open("demofile.txt");    // called open() function passing arg "demofile.txt"

    cout << "Now writing data to the file.\n";

    // Writing four names to the file.
    outputFile << "Bach\n";
    outputFile << "Beethoven\n";
    outputFile << "Mozart\n";
    outputFile << "Schubert\n";

    // Close the file
    outputFile.close();
    cout << "Done.\n";

    return 0;
}


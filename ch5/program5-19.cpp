// This program reads data from a file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("Friends.txt");
    string name;

    cout << "Reading data from the file.\n";

    inputFile >> name;      // Read name 1 from the file
    cout << name << endl;   // Display name 1

    inputFile >> name;      // Read name 2 from the file
    cout << name << endl;   // Display name 2

    inputFile >> name;      // Read name 3 from the file
    cout << name << endl;   // display name 3

    inputFile.close();

    return 0;
}


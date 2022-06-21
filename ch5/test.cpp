// test file for chapter 5 material
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    
//total 
//Friends.txt
//ListOfNumbers.txt
//NumericData.txt
//Sales.txt

    ifstream inputFile;
    //inputFile.open("Friends.txt");
        
    string line,
           filepath; 
    do
    {
    cout << "Enter the filename you want to read: ";
    getline(cin, filepath);
    //cout << "using default file\n";
    inputFile.open(filepath);
    if (inputFile.fail())
        cout << "Could not open: <<" << filepath << ">>\n";

    } while (inputFile.fail());

    cout << "File opened successfully." << endl
        << "Here are the lines from the file:\n";

    while (inputFile >> line)
    {
        cout << line << endl;
    }

    cout << "\n\nEnd of file\n";

    return 0;
}


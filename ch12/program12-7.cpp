#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string input;       // to hold file input
    fstream nameFile;   // file stream object

    nameFile.open("murphy.txt", ios::in);

    if (nameFile)
    {
        while (nameFile >> input)
        {
            cout << input;
        }
        nameFile.close();
    }
    else
    {
        cout << "ERROR: Cannot open file.\n";
    }

    return 0;
}

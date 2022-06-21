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
        // read a line from the file
        getline(nameFile, input);

        // while the last read operation was successfule, continue
        while (nameFile)
        {
            cout << input << endl;
            getline(nameFile, input);
        }
        nameFile.close();
    }
    else
    {
        cout << "ERROR: Cannot open file.\n";
    }

    return 0;
}

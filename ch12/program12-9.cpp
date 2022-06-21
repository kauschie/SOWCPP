#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input;

    fstream dataFile("names2.txt", ios::in);

    if (dataFile)
    {
        getline(dataFile, input, '$');

        while (dataFile)
        {
            cout << input << endl;
            getline(dataFile, input, '$');
        }

        dataFile.close();
    }
    else
    {
        cout << "Error: cannot open file.\n";
    }

    return 0;
}

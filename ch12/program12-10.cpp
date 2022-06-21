// this program ask s the user for a file name. the file is
// opened and its contents are displayed on the screen.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string fileName;
    char ch;
    fstream file;

    // get the file name
    cout << "Enter a file name: ";
    cin >> fileName;
    
    file.open(fileName, ios::in);

    // if the file was successfully opened, continue
    if (file)
    {
        file.get(ch);
        while (file)
        {
            cout << ch;
            file.get(ch);
        }
        file.close();
    }
    else
    {
        cout << fileName << " could not be opened.\n";
    }
    return 0;
}

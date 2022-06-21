#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch; // to hold a character

    fstream dataFile("sentence.txt", ios::out);

    cout << "Type a sentence and be sure to end it with a ";
    cout << "period.\n";

    // get a sentence from the user one character at a time
    // and write each character to the file.
    cin.get(ch);
    while (ch != '.')
    {
        dataFile.put(ch);
        cin.get(ch);
    }

    dataFile.put(ch);    // write the period

    // close the file
    dataFile.close();

    return 0;
}

// this program demonstrates the seekg function.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;    // to hold a character

    // open the file for input
    fstream file("letters.txt", ios::in);

    // move to byte 5 from the beginning of the file
    // (this is actually the 6th byte)
    // and read the character there
        file.seekg((5 * sizeof(char)), ios::beg);
    file.get(ch);
    cout << "byte 5 from beginning: " << ch << endl;

    // move to the 10th byte from the end of the file
    // and read the character there
    file.seekg(-(11 * sizeof(char)), ios::end);     // changed from text book
    file.get(ch);                               // my letters.txt file has a nullterm
    cout << "10th byte from end: " << ch << endl;

    // move to byte 3 from the current position
    // (the 4th byte) and read the character there.
    file.seekg((3 * sizeof(char)), ios::cur);
    file.get(ch);
    cout << "byte 3 from current: " << ch << endl;

    file.close();

    return 0;
}

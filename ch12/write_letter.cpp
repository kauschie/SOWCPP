#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    // open file
    fstream file("letters.txt", ios::out);
    cout << "Opening letter.txt...\n";
    if (file)
    {
        cout << "file opened successfully...\n";
        file << alphabet;
        file.close();
    }
    cout << "file finished writing. Now closing...\n";

    return 0;
}

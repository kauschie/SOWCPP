// this program uses the write and read functions
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int SIZE = 4;
    char data[SIZE] = {'A', 'B', 'C', 'D'};
    fstream file;

    // open file for output in binary mode
    // | operator allows for multiple flags
    file.open("test.dat", ios::out | ios::binary);
    
    // write the contents of the array to the file
    file.write(data, sizeof(data));

    // close the file.
    file.close();

    // open the file for read in binary mode.
    file.open("test.dat", ios::in | ios::binary);

    // read the contents of the file into the array
    file.read(data, sizeof(data));

    // display the contents of the array
    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;

    file.close();
   
    return 0;
}

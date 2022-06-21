// this program uses the write and read functions
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int SIZE = 10;
    fstream file;
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Open the file for binary output
    file.open("numbers.dat", ios::out | ios::binary);

    // write the contents of the array
    cout << "Writing data to the file.\n";
    file.write(reinterpret_cast<char *>(numbers), sizeof(numbers));

    // close the file
    file.close();

    // open the file in binary input mode
    file.open("numbers.dat", ios::in | ios::binary);

    // read the contents of the file in the array
    cout << "Now reading the data back into memory.\n";
    file.read(reinterpret_cast<char *>(numbers), sizeof(numbers));

    for (int i = 0; i < 10; i++)
        cout << numbers[i] << " ";
    cout << endl;

    file.close();

    return 0;
}

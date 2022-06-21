// this program demonstartes a pointer to const parameter
#include <iostream>
#include <iomanip>
using namespace std;

void displayValues(const int *, int);

int main()
{
    // array size
    const int SIZE = 6;

    // define an array of const ints
    const int array1[SIZE] = {1, 2, 3, 4, 5, 6};

    // define an array of nonconst ints
    int array2[SIZE] = {2, 4, 6, 8, 10, 12};

    // display the contents of the const array
    displayValues(array1, SIZE);

    // display the contents of the nonconst array
    displayValues(array2, SIZE);
    
    return 0;
}

void displayValues(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(2) << *(arr + i) << " ";
    }
    cout << endl;
}

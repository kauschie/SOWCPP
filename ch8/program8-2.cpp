// This program demonstrates the binarySearch function, which
// performs a binary search on an integer array.
#include <iostream>
using namespace std;

// function prototypes
int binarySearch(const int arr[], int size, int value);
const int SIZE = 20;

int main()
{
    int idNums[SIZE] = {101, 142, 147, 189, 199, 207, 222,
                        234, 289, 296, 310, 319, 388, 394,
                        417, 429, 447, 521, 536, 600};
    int results;    // to hold the search results
    int empID;      // to hold an employee ID

    // get an employee ID to search for
    cout << "Enter an employee ID to search for: ";
    cin >> empID;

    // search for the ID
    results = binarySearch(idNums, SIZE, empID);

    // if results contain -1 the ID was not found.
    if (results == -1)
        cout << "That number does not exist in the array.\n";
    else
    {
        // otherwise results contain the subscript
        // of the specified employee id in the array.
        cout << "That ID is found at element " << results
            << " of the array.\n";
    }

    return 0;
}

int binarySearch(const int arr[], int size, int value)
{
    int position = -1,      // 
        first = 0,          // first array element
        last = size-1,      // last array element
        middle;             // midpoint of search
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (arr[middle] == value)           // value found
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > value)       // if value is in the lower half
            last = middle - 1;
        else                                // if value is in the upper half
            last = middle + 1;
    }

    return position;
}

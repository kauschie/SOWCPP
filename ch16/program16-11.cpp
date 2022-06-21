// This program demonstrates the SimpleVector template
#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
    const int SIZE = 10;
    int count;

    // create a simplevector of ints
    SimpleVector<int> intTable(SIZE);

    // create a simplevector of doubles
    SimpleVector<double> doubleTable(SIZE);

    // store values in the two SimpleVectors
    for (count = 0; count < SIZE; count++)
    {
        intTable[count] = (count * 2);
        doubleTable[count] = (count * 2.14);
    }

    // display the values in the SimpleVectors
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    // use the standard + operator on the elements
    cout << "\nAdding 5 to each element of intTable"
        << " and doubleTable.\n";
    for (count = 0; count < SIZE; count++)
    {
        intTable[count] = intTable[count] + 5;
        doubleTable[count] = doubleTable[count] + 5.0;
    }

    // display values in the SimpleVectors
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    // use the standard ++ operator on the elements
    cout << "\nIncrementing each element of the intTable and"
        << " doubleTable.\n";
    for (count = 0; count < SIZE; count++)
    {
        intTable[count]++;
        doubleTable[count]++;
    }

// display the values in the SimpleVectors
cout << "These are the values in the intTable:\n";
for (count = 0; count < SIZE; count++)
    cout << intTable[count] << " ";
cout << endl;

cout << "These values are in doubleTable:\n";
for (count = 0; count < SIZE; count++)
    cout << doubleTable[count] << " ";
cout << endl;


    return 0;
}

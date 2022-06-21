// Chapter 7 Programming Challenge 1
// 10/14/21
// mike kausch
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void getNums(int numbers[], int arrSize);
int getHighest(int numbers[], int arrSize);
int getLowest(int numbers[], int arrSize);

int main()
{
    int numArray[10];
    getNums(numArray, 10);
    int highest = getHighest(numArray, 10);
    int lowest = getLowest(numArray, 10);
    cout << "The largest value you entered is " << highest << endl;
    cout << "The smallest value you entered is " << lowest << endl;

    return 0;
}

void getNums(int numbers[], int arrSize)
{
    cout << "~~Enter 10 numbers~~\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Number " << i+1 << ": ";
        cin >> numbers[i]; 
    }

}

int getHighest(int numbers[], int arrSize)
{
    int highest = numbers[0];
    for (int i = 1; i < arrSize; i++)
        highest = (numbers[i] > highest) ? numbers[i] : highest;

    return highest;
}

int getLowest(int numbers[], int arrSize)
{   
    int lowest = numbers[0];
    for (int i = 1; i < arrSize; i++)
        lowest = (numbers[i] < lowest) ? numbers[i] : lowest;

    return lowest;
}


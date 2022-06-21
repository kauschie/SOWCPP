// This program accepts four test scores, drops the lowest grade and averages the test scores
#include <iostream>
#include <iomanip>
using namespace std;

void getTestScores(double nums[], int size);
double getTotal(const double nums[], int size);
double getLowest(const double nums[], int size);

int main()
{
    const int SIZE = 4;
    double testScores[SIZE],
    total,
    lowestScore,
    average;

    cout << fixed << showpoint << setprecision(1);

    getTestScores(testScores, SIZE);

    total = getTotal(testScores, SIZE);

    lowestScore = getLowest(testScores, SIZE);

    total -= lowestScore;

    average = total / (SIZE - 1);

    cout << "The average with the lowest score dropped is " << average << ".\n";

    return 0;
}

void getTestScores(double nums[], int size)
{
    for (int index = 0; index < size; index++)
    {   
        do
        {
            cout << "Enter the score for test " << index + 1 << ": ";
            cin >> nums[index];
            if ( nums[index] < 1 )
                cout << "The number you enter cannot be negative.\n";
        } while ( nums[index] < 0 );
    }

}

double getTotal(const double nums[], int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++)
        total += nums[i];
    return total;
}
double getLowest(const double nums[], int size)
{
    double lowest;
    for (int index = 0; index < size; index++)
    {
        if (index == 0)
            lowest = nums[index];
        if (nums[index] < lowest)
            lowest = nums[index];
    }
    return lowest;
}


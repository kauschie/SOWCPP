// This program displays the number 1 through 10 and their squares
#include <iostream>
using namespace std;

int main()
{
    const int MIN_NUMBER = 1,       // starting value
          MAX_NUMBER = 10;          // ending value

    int num;

    cout << "Number Number Squared\n";
    cout << "----------------------\n";

    for (num = MIN_NUMBER; num <= MAX_NUMBER; num++)
        cout << num << "\t\t" << num * num << endl;

    return 0;
}


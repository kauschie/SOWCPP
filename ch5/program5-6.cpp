// Checkpoint ##
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    const int MIN_NUMBER = 1,   // Starting number to square
              MAX_NUMBER = 10;  // Maximum to square

    int num = MIN_NUMBER;   // counter

    cout << "Number Number Squared\n";
    cout << "----------------------\n";
    while (num <= MAX_NUMBER)         
    {
        cout << num << "\t\t" << (num * num) << endl;
        num++;          // increment counter in expression
    }




    return 0;
}


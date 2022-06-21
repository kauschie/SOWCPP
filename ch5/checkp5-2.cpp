// Checkpoint 5.2
// Checkpoint 5.3
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    // Checkpoint 5.2
/*  int number;

    cout << "Enter a number in the range of 10 through 25: ";
    cin >> number;
    while (number < 10 || number > 25)
    {
        cout << "Not in range. Enter a number between 10 and 25: ";
        cin >> number;
    }




    // Checkpoint 5.2
*/ 
    char input;
    cout << "'Y','y','N', or 'n': ";
    cin >> input;
    while ((input != 'Y') && (input != 'y') && (input != 'N') && (input != 'n'))
    {
        cout << "Not a correct response. 'Y','y','N', or 'n': ";
        cin >> input;
    }












    cout << "Test complete. Good bye.\n";


    return 0;
}


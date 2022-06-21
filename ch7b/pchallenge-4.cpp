// Chapter 7 Programming Challenge 4
// 10/14/21
// Michael Kausch
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void larger_than(int inputArr[], int arrSize, int num);

int main()
{

    int input[10];
    for (int i = 0; i < 10; i++)
        input[i] = i;

    int n;

    while (n != -1)
    {
        cout << "Enter a number between 0 and 9: ";
        cin >> n;
        if (n != -1)
        {   
            larger_than(input, 10, n);
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}

void larger_than(int inputArr[], int arrSize, int num)
{
    bool nums_present = false;
    for (int i = 0; i < arrSize; i++)
    {
        if (inputArr[i] > num)
        {
            if (nums_present == false)
            {
                cout << "The following numbers are larger than " << num << ": ";
                nums_present = true;
            }
            cout << inputArr[i] << " ";
        }
    }
    if (nums_present == false) 
        cout << "There were no numbers larger than " << num << " in the array.\n";
}

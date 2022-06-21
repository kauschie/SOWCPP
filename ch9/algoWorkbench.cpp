#include <iostream>
using namespace std;

int main()
{
    // # 24
    double value = 29.7;
    double *ptr = &value;

    cout << *ptr << endl;

    // #25

    int set[10];
    *(set + 7) = 99;

    // #26
    
    int *nums = new int[20];
    for (int i = 0; i < 20; i++)
    {
        cout << "Enter a value for number " << i+1 << ": ";
        cin >> *(nums+i);
    }

    for (int i = 0; i < 20; i++)
        cout << "Number " << i+1 << " is: " << *(nums+i) << endl;

    delete [] nums;

    // #27

    // delete [] tempNumbers;

    // #28

    void getNumber(int *n)
    {
        cout << "Enter a number: ";
        cin >> *n;
    }

    // #29

    const int num = 5;
    const int *ptr = &num;

    // #30

    int num = 10;
    int * const ptr = &num;



    return 0;
}

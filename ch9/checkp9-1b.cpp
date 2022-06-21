#include <iostream>
using namespace std;

int main()
{

    // 9.1
    cout << &count;

    // 9.2
    float* fltPtr = nullptr;

    // 9.3
    // multiplication
    // pointer definition
    // dereference a variable (indirection opertor)

    // 9.4
    // output:
    // 50 60 70
    // 500 300 140

    // 9.5
    int arr[] = {100, 200, 300};
    for (int x = 0; x < 100; x++)
       cout << *(arr+x) << endl; 

    // 9.6
    // 10 * 4 = 40 bytes so,
    // 12000 + 40 = 12040

    // 9.7
    // A) valid
    // B) valid
    // C) invalid - can't do division with addresses
    // D) invalid - can't do multiplication with addresses
    // E) valid
    
    // 9.8
    // A) valid
    // B) valid
    // C) invalid - can't assign an address for a double to a int pointer
    // D) valid
    // E) invalid - the pointer assignment to a variables address needs to occur after the
    //              variable as been defined


    return 0;
}


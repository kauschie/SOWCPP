// this program demonstrates the bad_alloc exception
#include <iostream>
#include <new>  // needed for bad_alloc
using namespace std;

int main()
{
    double *ptr = nullptr;  // pointer to double

    try
    {
        new double [10000];     // if new operator fails..
    }
    catch (bad_alloc)       // cathces error and error message
    {                   // is displayed
        cout << "Insufficient memory.\n";
    }

    return 0;
}

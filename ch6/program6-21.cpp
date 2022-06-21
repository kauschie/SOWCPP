// This program shows that local variables do not retain
// their values between function calls.
#include <iostream>
using namespace std;

// Function prototype
void showLocal();

int main()
{
    showLocal();
    showLocal();

    return 0;
}

void showLocal()
{
    int localNum = 5; // Local variables

    cout << "localNum is " << localNum << endl;
    localNum = 99; 

}


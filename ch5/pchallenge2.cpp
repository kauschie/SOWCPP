// Characters for the ASCII Codes
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char code;

    cout << "--ASCII\tCode\tList--\n";

    for (int x = 0; x <= 127 ; x++)
    {
        code = x;
        cout << code << " "; 
        
        if (x % 16 == 0)
            cout << endl;
    }

    cout << endl << endl;
    return 0;
}

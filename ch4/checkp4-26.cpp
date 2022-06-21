#include <iostream>
using namespace std;

int main()
{
    const int UPPER = 8, LOWER = 2;
    int num1, num2, num3 = 12, num4 = 3;
    num1 = num3 < num4 ? UPPER : LOWER;
    num2 = num4 > UPPER ? num3 : LOWER;
    cout << num1 << " " << num2 << endl;
    return 0;
}

//
//Output:
//2 2

#include <iostream>
using namespace std;

int main()
{
    
    int numBooks, numCoupons;
    cout << "How many books are being purchased? ";
    cin >> numBooks;

    if (numBooks < 1)
        numCoupons = 0;
    else if (numBooks < 3)
        numCoupons = 1;
    else if (numBooks < 5)
        numCoupons = 2;
    else
        numCoupons = 3;

    cout << "The number of coupons to give is "
        << numCoupons << endl;

    return 0;
}


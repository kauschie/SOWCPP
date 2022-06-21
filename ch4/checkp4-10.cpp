#include <iostream>
using namespace std;

int main()
{
    
    // Checkpoint 4.10

    double commissionRate;
    int sales = 50001;
    int bonus;

    if (sales > 50000)
    {
        commissionRate = 0.25;
        bonus = 250;
    }

    cout << commissionRate << " | " << bonus << endl;
    
    // Checkpoint 4.10
    double interestRate = 1.25;
    double balance = 500;

    if (interestRate > 0.7)
    {
        cout << "This account earns a $10 bonus.\n";
        balance += 10.0;
    }



    return 0;

}


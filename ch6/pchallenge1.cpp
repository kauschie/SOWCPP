// Checkpoint ##
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double calculateRetail(double, double);

int main()
{
    double cost,
           markup,
           retailPrice;
    do
    {
        cout << "Enter the wholesale cost: ";
        cin >> cost;
        cout << "Enter the markup: ";
        cin >> markup;
        if (cost < 0 || markup < 0)
            cout << "The cost and markup need to be positive\n";
    } while (cost < 0 || markup < 0);

    markup /= 100;
    retailPrice = calculateRetail(cost, markup);
    cout << fixed << showpoint << setprecision(2);
    cout << "Cost: " << cost << "\tMarkup: " << markup
        << "\tRetail Price: " << retailPrice << endl;
    
    return 0;
}

double calculateRetail(double wholesale, double percent)
{
    return wholesale + (wholesale * percent);
}


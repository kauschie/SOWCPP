// 5.6 
// name three expressions that appear inside the parentheses in the for loop's header:
//  initializer, test expression, update expression
//
//  5.7
//
//  A) int count = 1;
//  B) count <= 50;
//  C) count++
//  D) for (int count = 1; count <=50; count++)
//      cout << "I love to program\n";
//
//  5.8
//
//  int x;
//  for (x = 5; x <= 14; x+=3)
//      cout << x << endl;
//  cout << x << endl;
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // 5.9
/*    string name = "Michael";
    cout << fixed << showpoint << setprecision(1);
    cout << "Name" << "\t\t" << "i" << endl;
    cout << "--------------------" << endl;
    for (double i = 1; i <= 10; i++)
        cout << name << "\t\t" << i << endl;
*/
    // 5.10
/*
    for (int i = 1; i <= 49; i+=2)
        cout << i << endl;
    cout << endl << endl;

    for (int i = 1; i <= 49; i++)
    {   if ( i % 2 == 1)
            cout << i << endl;
    }
*/

    // 5.11

    for (int i = 0; i <= 100; i+=5)
    {
        cout << i << endl;
    }
    

    return 0;
}


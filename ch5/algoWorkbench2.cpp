#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*
     * #35
     int num, product = 0;
     while ( product < 100 )
     {
     cout << "Enter a number: ";
     cin >> num;
     product = num * 10;
     }

     * 
     *  # 36
     int num1, num2, sum = 0;
     char c;
     do
     {
     cout << "Enter two numbers: ";
     cin >> num1 >> num2;
     cout << "Sum: " << num1 + num2 << endl;
     cout << "Do you wish to go again? (y or n): ";
     cin >> c;
     } while (c == 'y' || c == 'Y');

     * 
     * # 37
     for (int i = 0; i <= 1000; i+=10)
     cout << i << " ";


    //  # 38

    int num, sum = 0;
    for (int i = 0; i < 10; i++)
    {
    cout << "Enter n" << i+1 << ": ";
    cin >> num;
    sum += num;
    }
    cout << "sum: " << sum << endl;


    // # 39

    for (int i = 0; i < 10; i++)
    {
    for (int j = 0; j < 15; j++)
    cout << '#';
    cout << endl;
    }


    // # 40

    ofstream fout("Numbers.txt");
    if (fout) 
    {
        for (int i = 1; i <= 100; i++)
            fout << i << endl;

    }

*/

    // # 41

    ifstream fin("Numbers.txt");
    if (fin)
    {
        int num;
        while (fin >> num)
        {
            cout << num << " ";
        }


    }

    fin.close();

    return 0;

}

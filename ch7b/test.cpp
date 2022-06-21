#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void func_vals();

int numbers[5];

int main()
{

    int more_nums[5];

    cout << "main vars:\n";

    for ( int values : more_nums )
        cout << values << endl;

    cout << "global vars:\n";

    for (int values : numbers)
        cout << values << endl;

    func_vals();

    return 0;
}

void func_vals()
{
    int f_vals[5];

    cout << "Function vals:\n";
    for (int values : f_vals)
        cout << values << endl;

}

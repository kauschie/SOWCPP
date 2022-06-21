#include <iostream>
using namespace std;

// #33
double half(double num);

// # 35
void timesTen(int num);

// # 37
void getNumber(int & num);

int main()
{
    // #32
    //showValue(5);

    // #34
    //int result;
    //result = cube(4);

    // #36
    // int age;
    // double income;
    // char initial;

    // display(age, income, initial);


    return 0;
}

// #33
double half(double num)
{
    return num/2;
}

// #35
void timesTen(int num)
{
    cout << num * 10 << endl;
}

// # 37
void getNumber(int & num)
{
    do
    {
        cout << "Enter a number between 1 and 100: ";
        cin >> num;
    } while (num < 1 || num > 100);

}


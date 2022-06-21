#include <iostream>
using namespace std;

void show_num(int num = 10);

int main()
{
    int num[1] = {5};

    for ( int val : num )
    {
        val = 69;
    }
    cout << num[2] << endl;

    return 0;
}

void show_num(int num)
{
    cout << "Here's a number: " << num << endl;
}


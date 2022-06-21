#include <iostream>
using namespace std;

void func1(int num, int num2 = 3);
void func1(int num);

int main()
{
    func1(2, 2);


    return 0;
}


void func1(int num, int num2)
{
    cout << "func1 with default called\n";
    cout << "num: " << num << endl;
    cout << "num2: " << num2 << endl;
}

void func1(int num)
{
    cout << "func1 with no default called\n";
    cout << "num: " << num << endl;
}

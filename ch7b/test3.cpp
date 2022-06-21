#include <iostream>
using namespace std;

void myFunc(int (& nums)[10]);

int main()
{
    int intArr[10] = {1};
    myFunc(intArr);
    for (int val : intArr)
        cout << val << endl;


    return 0;
}


void myFunc(int (& nums)[10])
{
    for (int val : nums)
        cout << val << endl;

}


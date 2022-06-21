#include <iostream>
using namespace std;
int main()
{
    char letter;

    cout << "Enter a letter to see its corresponding ASCII value: ";
    cin >> letter;
    cout << static_cast<int>(letter) << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char first, middle, last, dot;
    string sentence;

    first = 'M';
    middle = 'A';
    last = 'K';
    dot = '.';
    sentence = "Your initials are: ";

    cout << sentence << first << dot << middle << dot << last << dot << endl;
    return 0;
}
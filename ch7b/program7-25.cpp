// This program demonstrates the range based for loop with a vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // define and initialize a vector
    vector<int> numbers { 10, 20, 30, 40, 50};

    // display the vector elements
    for ( int num : numbers )
        cout << num << " ";

    return 0;
}


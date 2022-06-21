// This program demonstrates the range based for loop with a vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // define and initialize a vector
    vector<int> numbers(5); 
    
    for (int &val : numbers)
    {
        cout << "Enter an integer number: ";
        cin >> val;
    }

    // display the vector elements
    cout << "Here are the values you entered:\n";
    for (int val : numbers)
        cout << val << " ";

    return 0;
}


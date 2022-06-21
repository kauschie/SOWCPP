// This program has three functions: main, first, and second.
#include <iostream>
using namespace std;

// Function Prototypes
void first();
void second();

int main()
{
    cout << "I am starting in function main.\n";
    first();
    cout << "Back in main.\n";
    second();
    cout << "Back in the function main again.\n";
    return 0;
}

void first()
{
    cout << "I am now inside the first function.\n";
}

void second()
{
    cout << "I am now inside the second function.\n";
}



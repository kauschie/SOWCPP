// This program has two functions: main and displayMessage
#include <iostream>
using namespace std;

void displayMessage()
{
    cout << "Hello from the function displayMessage.\n";
}

//**************************************
// Function main
//**************************************

int main()
{
    cout << "Hello from main.\n";
    displayMessage();
    cout << "Hello from main again.\n";
    return 0;
}

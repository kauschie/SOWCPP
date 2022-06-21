#include <iostream>
using namespace std;

int main()
{
    short numbers[] = {10, 20, 30, 40, 50};
    short* numPtr = numbers;

    cout << "The first element of the array is: " << *numbers << endl;
    cout << "Using numPtr, it is also: " << *numPtr << endl;
    numPtr++;
    cout << "Using pointer notation, numbers[1] is also: "<< *(numbers+1) << endl; 
    cout << "I used pointer arithmetic to increment numPtr...\n"
        << "so the next element is also: " << *numPtr << endl;
    cout << "this displays an address (numbers+1): " << (numbers+1) << endl;
    cout << "using the pointer it is: " << numPtr << endl;
    cout << "this is also the address using &numbers[1]: " << &numbers[1] << endl;


    return 0;
}


#include <iostream>
using namespace std;

int main()
{
    /* # 41
       int names[20] = {0};
       for (int i = 0; i < 20; i++)
       cout << names[i] << ' ';
       cout << endl;
       for (int val : names)
       cout << val << ' ';
       cout << endl;
       */
    
    /* # 42
    int numberArray1[100] = {1}, numberArray2[100] = {0};

    for (int val : numberArray1)
        cout << val << ' ';
    cout << endl;
    for (int val : numberArray2)
        cout << val << ' ';
    cout << endl;
    for (int i = 0; i < 100; i++)
        numberArray2[i] = numberArray1[i];
    for (int val : numberArray1)

        cout << val << ' ';
    cout << endl;
    for (int val : numberArray2)
        cout << val << ' ';
    cout << endl;
    */

    // # 45
    /*
    string names[12] = {""};
    int pop[12] = {0};
    for (int i = 0; i < 12; i++)
        cout << "Country " << names[i] << " has population " << pop[i] << endl;
    */

    /*
    int total = 0;
    int count;
    int numberArray1[25], numberArray2[25];
    for (count = 0; count < 25; count++)
        numberArray1[count] = count+1;
    for (int val : numberArray1)
        total += val;
    cout << total << endl;
    total = 0;
    for (count = 0; count < 24; count++)
        total += numberArray1[count];
    cout << total << endl;
    */
    string strArray[5] = {"word"};
    for (string word : strArray)
        cout << word << " ";




    return 0;
}


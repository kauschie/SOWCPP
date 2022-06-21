// algorithm workbench
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int names[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int Array1[100], Array2[100];
    // 41
    for (int i = 0; i < 20; i++)
        cout << names[i] << " ";
    
    for (int value : names)
        cout << value << " ";

    // 42
    for (int i = 0; i < 100; i++)
    {
        Array1[i] = 1;
    }

    for (int i = 0; i < 100; i++)
    {
        Array2[i] = Array1[i];
        cout << "Array1: " << Array1[i] << " || Array2: " << Array2[i] << endl;

    }


    // 43

    int emp_id[10];
    double emp_gross_pay[10];

    for (int i = 0; i < 10; i++)
    {   
        cout << emp_id[i] << " " << emp_gross_pay[i] << endl;
    }


    // 44

    int grades[30][10];

    // 45
    
    string countries[12];
    int population[12];
    cout << endl << "country   ||   population\n";
    for (int i = 0; i < 12; i++)
    {
        cout << countries[i] << " : " << population[i] << endl;
    }

    // 46
    // No it wont - it misses the last element in the array because the for loop isn't set up correctly

    // 47
    //
    int numberArray[9][11];
    numberArray[0][0] = 145;
    numberArray[8][10] = 18;
    
    // 48
    float values[10][20];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
            values[i][j]=1;
    }

    double total = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
            total += values[i][j];
    }
    cout << "\nQ48) total = " << total << endl; 




    return 0;
}

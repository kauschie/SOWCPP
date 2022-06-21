#include <iostream>
using namespace std;

void initialize_2d_array(double sales[][10], int num);
void print_2d_array(double sales[][10]);

int main()
{
    string words[20] = {""};
    //double sales[8][10] = {1};
   // initialize_2d_array(sales, 0);
    //sales[7][9] = 1;
    //print_2d_array(sales);
    for (int i = 0; i < 20; i++)
        cout << words[i] << endl;

    return 0;
}
void initialize_2d_array(double sales[][10], int num)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sales[i][j] = num;
        }

    }
}

void print_2d_array(double sales[][10])
{   
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << sales[i][j] << ' ';
            count++;
        }
    }
    cout << "\nThere were " << count << " elements.\n";
}

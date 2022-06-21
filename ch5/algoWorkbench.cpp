// 35
// int product = 0, num;
// while (product < 100)
//      cin >> num;
//      product = num * 10;
//
//
// 36
//
int num1, num2;
bool answer;

do 
{
    cout << "enter two numbers: ";
    cin >> num1 >> num2;
    cout << num1+num2 << endl;
    cout << "Do you wish to go again? (y/n)";
    cin >> answer;
} while (answer == 'y')

for (int i = 0; i <=1000; i+=10)
    cout << i << endl;

int sum = 0, num = 0;
for (int i = 1; i <= 10; i++)
{   cout << "Enter a number: ";
    cin >> num;
    sum += num;
}

for (int i = 1; i <= 10; i++)
{
    for (int j = 1; j <= 15; j++)
        cout << "#";
    cout << endl;
}

for (int count = 0; count < 50; count++)
    cout << "count is " << count << endl;

int x = 50;
while (x > 0)
{
    cout << x << " seconds to go.\n";
    x--;
}

// 44
//
// #include <fstream>
// using namespace std;
// ofstream opFile;
// opFile.open("Numbers.txt")
// int main()
// {
// for (int i = 1; i<=100; i++)
//      opFile << i << endl;
// opFile.close();
// return 0;
// }
//

//45
//ifstream iFile("Numbers.txt");
//int number= 0;
//int total = 0;
//while (iFile >> number)
//  total += number;
//cout << "The total is: " << total << endl;
//iFile.close();
//  

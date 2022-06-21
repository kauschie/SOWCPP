// checkpoints for ch11
// michael kausch
// 11/09/21
#include <iostream>
#include <string>
using namespace std;


// checkp 11.1
struct Account
{
    string acct_num;
    double balance;
    double interest_rate;
    double avg_monthly_balance;
};

 // checkp 11.2
//    Account savings = {"ACZ42137-B12-7", 4512.59, 0.04, 4217.07};
    
struct Movie
{
    string name;
    string director;
    string producer;
    int year;

};

int main()
{
  
    // checkp 11.3
    Movie favorite;

    cout << "Enter the following data about your\n";
    cout << "favorite movie.\n";
    cout << "name: ";

    // 
    getline(cin, favorite.name);
    cout << "Director: "; 
    getline(cin, favorite.director);

    
    cout << "Producer: "; 
    getline(cin, favorite.producer);


    cout << "Year of release: "; 
    cin >> favorite.year;
    

    cout << "Here is data on your favorite movie:\n";
    cout << "Name: " << favorite.name << endl;
    cout << "Director: " << favorite.director << endl;
    cout << "Producer:: " << favorite.producer << endl;
    cout << "Year of release: " << favorite.year << endl;



    return 0;
}

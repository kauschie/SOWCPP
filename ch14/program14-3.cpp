#include <iostream>
#include <iomanip>
using namespace std;

class Budget
{
    private:
        static double corpBudget;   // static member
        double divisionBudget;
    public:
        Budget()
        {  divisionBudget = 0;  }

        void addBudget(double b)
        { divisionBudget+= b;
            corpBudget+= b; }
        
        double getDivisionBudget() const
        {  return divisionBudget;  }

        double getCorpBudget() const
        {  return corpBudget;  }

        static void mainOffice(double);     // static member function

};

double Budget::corpBudget = 0;

void Budget::mainOffice(double  moffice)
{
    corpBudget += moffice;
}   

int main()
{
    int count;
    const int NUM_DIVISIONS = 4;
    double mainOfficeRequest;       // main office budget request
    Budget divisions[NUM_DIVISIONS];        // array of division objects

    cout << "Enter the main office's budget request: ";
    cin >> mainOfficeRequest;
    Budget::mainOffice(mainOfficeRequest);

    for (count = 0; count < NUM_DIVISIONS; count++)
    {
        double budgetAmount;
        cout << "Enter the budget request for division ";
        cout << count + 1 << ": ";
        cin >> budgetAmount;
        divisions[count].addBudget(budgetAmount);
    }

    // Display the budget requests and the corporate budget
    cout << fixed << showpoint << setprecision(2);
    cout << "\nHere are the division budget requests:\n";
    for (count = 0; count < NUM_DIVISIONS; count++)
    {   
        cout << "\tDivison " << count+1 << "\t$";
        cout << divisions[count].getDivisionBudget() << endl;
    }
    cout << "\tTotal Budget Requests:\t$";
    cout << divisions[0].getCorpBudget() << endl;

    return 0;
}

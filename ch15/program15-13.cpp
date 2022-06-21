#include <iostream>
#include <iomanip>
#include "PassFailExam.h"
using namespace std;

void displayGrade(const GradedActivity *);

int main()
{
    GradedActivity test1(88.0);

    PassFailExam test2(100, 25, 70.0);

    cout << "Test 1:\n";
    displayGrade(&test1);        // GradedActivity obj`
    cout << "Test 2:\n";
    displayGrade(&test2);        // PassFailExam object


    return 0;
}

void displayGrade(const GradedActivity * activity)
{
    cout << setprecision(1) << fixed;
    cout << "The activity's numeric score is "
        << activity->getScore() << endl;
    cout << "The activity's letter grade is "
        << activity->getLetterGrade() << endl;
}

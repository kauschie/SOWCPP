#include <iostream>
#include <iomanip>
#include "PassFailActivity.h"
using namespace std;

void displayGrade(const GradedActivity &);

int main()
{
    PassFailActivity test(70);

    test.setScore(72);

    displayGrade(test);

    return 0;
}

void displayGrade(const GradedActivity & activity)
{
    cout << setprecision(1) << fixed;
    cout << "The activity's numeric score is "
        << activity.getScore() << endl;
    cout << "The activity's letter grade is "
        << activity.getLetterGrade() << endl;
}
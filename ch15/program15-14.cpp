// this program uses polymorphism and an array of GradedActivity pointers called test
// some pointers are GradedActivity objects and some are PassFailExam objects
// 
#include <iostream>
#include <iomanip>
#include "PassFailExam.h"
using namespace std;

// f() prototypes
void displayGrade(const GradedActivity *);

int main()
{
    const int NUM_TESTS = 4;

    GradedActivity *tests[NUM_TESTS] = { new GradedActivity(88.0),
                                         new PassFailExam(100, 25, 70.0),
                                         new GradedActivity(67.0),
                                         new PassFailExam(50, 12, 60.0) };
    for (int i = 0; i < NUM_TESTS; i++)
    {
        cout << "Test #" << i+1 << ":\n";
        displayGrade(tests[i]);
        cout << endl;
    }

    return 0;
}

void displayGrade(const GradedActivity * activity)
{
    cout << fixed << setprecision(1);
    cout << "The activity's numeric score is "
        << activity->getScore() << endl;
    cout << "The activity's letter grade is "
        << activity->getLetterGrade() << endl;
}


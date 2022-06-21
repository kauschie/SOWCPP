// this program demonstrates a class that redefines 
// a base class
#include <iostream>
#include <iomanip>
#include "CurvedActivity.h"
#include "GradedActivity.h"
using namespace std;

int main()
{
    double numericScore, 
            percentage;
    
    // Define a CurvedActivity object
    CurvedActivity exam;

    // get the unadjusted score
    cout << "Enter the student's raw numeric score: ";
    cin >> numericScore;

    // get the curve percentage
    cout << "Enter the curve percentage for this student: ";
    cin >> percentage;

    // sends the values to the exam object.
    exam.setPercentage(percentage);
    exam.setScore(numericScore);

    // display the grade data
    cout << fixed << setprecision(2);
    cout << "The raw score is " << exam.getRawScore() << endl;
    cout << "The curved score is " << exam.getScore() << endl;
    cout << "The curved grade is " << exam.getLetterGrade() << endl;

    return 0;
}
// this program demonstrates the PassFailExam class
#include <iostream>
#include <iomanip>
#include "PassFailExam.h"
#include "PassFailActivity.h"

using namespace std;

int main()
{
    int questions;
    int missed;
    double minPassing;

    // get # of Q's on exam
    cout << "How many questions are on the exam? ";
    cin >> questions;

    cout << "How many questions did the student miss? ";
    cin >> missed;
    
    cout << "Enter the minimum passing score for this test: ";
    cin >> minPassing;

    PassFailExam exam(questions, missed, minPassing);

    cout << fixed << setprecision(1);
    cout << "\nEach question counts " << exam.getPointsEach()
        << " points.\n";
    cout << "The minimum passing score is " << exam.getMinPassingScore() << endl;
    cout << "The student's exam score is " << exam.getScore() << endl;
    cout << "The student's grade is " << exam.getLetterGrade() << endl;
    return 0;
}

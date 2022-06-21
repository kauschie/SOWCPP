#include <iostream>
#include <iomanip>
#include "FinalExam.h"

using namespace std;
/*
class GradedActivity
{
    protected:
        double score;                               //      gets inhereted by FinalExam but is
    public:                                         //      only accessible with the inherited 
        // Default constructor                      //      GradedActivity member functions
        GradedActivity() {  score = 0;  }

        GradedActivity(double s) { score = s; } 

        // Mutator functions

        void setScore(double s) { score = s; }

        // Accessor functions
        double getScore() { return score; }

        char getLetterGrade() const;

        // operator functions

        friend istream& operator>>(istream &in, GradedActivity& obj)
        {
            in >> obj.score;

            return in;
        }
        
};

char GradedActivity::getLetterGrade() const
{
    char letterGrade;
        
    if (score > 89)
        letterGrade = 'A';
    else if (score > 79)
        letterGrade = 'B';
    else if (score > 69)
        letterGrade = 'C';
    else if (score > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';

    return letterGrade;
}

class FinalExam : public GradedActivity
{
    private:
        int numQuestions;   // number of questions
        double pointsEach;  // points for each qeustion
        int numMissed;      //  num questions missed

    public:
        // default constructor
        FinalExam()
        {    numQuestions = 0;
            pointsEach = 0.0;
            numMissed = 0;   }

        // overloaded constructor
        FinalExam(int questions, int missed)
        {
            set(questions, missed);
        }

        // mutators
        void set(int q, int m);
        void adjustScore();

        // accessors
        double getNumQuestions() const {   return numQuestions; }
        double getPointsEach() const { return pointsEach; }
        int getNumMissed() const { return numMissed; }

        // friends
        friend ostream& operator<<(ostream& out, FinalExam& obj)
        {
            out << fixed << showpoint << setprecision(2);
            out << "\nEach question counts " << obj.getPointsEach() << " points.\n";
            out << "The adjusted exam score is " << obj.getScore() << endl;
            out << "The exam grade is " << obj.getLetterGrade() << endl;

            return out;
        }
};

void FinalExam::set(int q, int m)
{
    double numericScore;    // to hold the numeric score
    numQuestions = q;
    numMissed = m;

    pointsEach = 100.0 / numQuestions;

    numericScore = 100.0 - (numMissed * pointsEach);

    setScore(numericScore);

    adjustScore();
}

void FinalExam::adjustScore()
{
   double fraction = score - static_cast<int>(score); 

   if (fraction >= 0.5)
   {    
       // adjust the score variable in the gradedActivity class
       score += (1.0 - fraction);
   }
}
*/
// This program demonstrates the GradedActivity class
int main()
{

    int questions, missed;

    cout << "How many questions are on the final exam? ";
    cin >> questions;

    cout << "How many questions did the student miss? ";
    cin >> missed;
    
    FinalExam test(questions, missed);

    // Display the adjusted test results
    
    cout << test;
    
//    cout << setprecision(2);
//    cout << "\nEach question counts " << test.getPointsEach() << " points.\n";
//    cout << "The exam score is " << test.getScore() << endl;
//    cout << "The exam grade is " << test.getLetterGrade() << endl;

    return 0;
}

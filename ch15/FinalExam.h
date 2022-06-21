#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "GradedActivity.h"
#include <iomanip>


class FinalExam : public GradedActivity
{
    private:
        int numQuestions;   // number of questions
        double pointsEach;  // points for each question
        int numMissed;      // Number of questions missed
    public:
        // default constructor
        FinalExam()
        {   numQuestions = 0;
            pointsEach = 0.0;
            numMissed = 0; }
        
        // Constructor
        FinalExam(int questions, int missed)
        { set(questions, missed);}

        // Mutator function
        void set(int, int); // defined in FinalExam.cpp
        void adjustScore(); // defined in FinalExam.cpp

        // Accessor functions
        double getNumQuestions() const
        {  return numQuestions;  }

        double getNumMissed() const
        {  return numMissed;  }
        
        double getPointsEach() const
        {  return pointsEach;  }

        

        friend ostream& operator<<(ostream& out, FinalExam& obj)
        {
            out << fixed << showpoint << setprecision(2);
            out << "\nEach question counts " << obj.getPointsEach() << " points.\n";
            out << "The adjusted exam score is " << obj.getScore() << endl;
            out << "The exam grade is " << obj.getLetterGrade() << endl;

            return out;
        }
};

#endif
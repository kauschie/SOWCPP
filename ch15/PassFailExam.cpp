#include "PassFailExam.h"


void PassFailExam::set(int questions, int missed) // defined in PassFailExam.cpp
{
    double numericScore;        // holds numeric score

    // set the number of questions and number missed
    numQuestions = questions;
    numMissed = missed;

    // calc the points for each questions
   pointsEach = 100.0 / numQuestions;

   // calc the numeric score for the exam
   numericScore = 100.0 - (numMissed * pointsEach);
   setScore(numericScore);  
}

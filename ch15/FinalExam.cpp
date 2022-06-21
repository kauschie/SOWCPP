#include "FinalExam.h"

void FinalExam::set(int questions, int missed)
{
    numQuestions = questions;
    numMissed = missed;
    pointsEach = 100.0 / numQuestions;
    setScore((100.0 - (pointsEach * numMissed)));
    adjustScore();
}

void FinalExam::adjustScore()
{
    double fraction = score - static_cast<int>(score);

    if (fraction >= 0.5)
    {   // adjust sccore var in GradedActivity class
        score += (1.0 - fraction);
    }
}
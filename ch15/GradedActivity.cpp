#include "GradedActivity.h"

//void GradedActivity::determineGrade()
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

    // letter = letterGrade;
    return letterGrade;
}
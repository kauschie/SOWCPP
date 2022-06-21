#include "CurvedActivity.h"
#include "GradedActivity.h"

void CurvedActivity::setScore(double s)
{
    rawScore = s;
    GradedActivity::setScore(rawScore * percentage);
}
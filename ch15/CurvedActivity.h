#ifndef CURVEDACTIVITY_H
#define CURVEDACTIVITY_H
#include "GradedActivity.h"

class CurvedActivity : public GradedActivity
{
    protected:
        double rawScore;    // Unadjusted score
        double percentage;  // Curve Percentage
    public:
        // Default constructor
        CurvedActivity() : GradedActivity()
        { rawScore = percentage = 0.0; }

        // Mutator functions
        void setScore(double s);

        void setPercentage(double c)
        { percentage = c; }

        // Accessor Functions
        double getPercentage() const { return percentage; }
        double getRawScore() const { return rawScore; }
};
#endif
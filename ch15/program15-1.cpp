#include <iostream>
#include "GradedActivity.h"
using namespace std;

/*class GradedActivity
{
    private:
        double score;
    public:
        // Default constructor
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
}*/

// This program demonstrates the GradedActivity class
int main()
{

    // double testScore;

    GradedActivity test;

    cout << "Enter a numeric test score from the user: ";
    
    // without overloaded >>
    // cin >> testScore;
    // test.setScore(testScore);


    // with overloaded >>
    cin >> test;


    cout << "The grade for that class is " << test.getLetterGrade() << endl;

    return 0;
}

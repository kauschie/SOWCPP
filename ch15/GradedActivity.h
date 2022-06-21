#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H
#include <iostream>

class GradedActivity
{
    protected:
        double score;   // to hold a numeric score
        //char letter;       // to hold the letter grade
        //void determineGrade();  // determines the grade
    public:
        // default constructor
        // GradedActivity() { letter = ' '; score = 0.0; }
        GradedActivity() { score = 0.0; }

        // constructors
        
        GradedActivity(double s) { score = s; }
        
        // mutators
        void setScore(double s) 
        { 
            score = s; 
            //determineGrade(); 
        }

        // accessor functions
        double getScore() const { return score; }

        //virtual keyword binds funcion calls dynamically 
        virtual char getLetterGrade() const; //{ return letter; }

        // friends
        friend std::istream& operator>>(std::istream &in, GradedActivity& obj)
        {
            in >> obj.score;

            return in;
        }
};
#endif

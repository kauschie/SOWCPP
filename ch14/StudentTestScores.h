#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores
{
    private:
        string studentName; // the student's name
        double *testScores; // points to array of test scores
        int numTestScores;  // number of test scores

        // private member function to create an array of test scores
        void createTestScoresArray(int size)
        {   numTestScores = size;
            testScores = new double[size];
            for (int i = 0; i < size; i++)
                testScores[i] = DEFAULT_SCORE; }
        
    public:
        // constructor
        StudentTestScores(string name, int numScores)
        {   studentName = name;
            createTestScoresArray(numScores); }

        // copy constructor
        StudentTestScores(StudentTestScores &obj)
        {
           studentName = obj.studentName;
           numTestScores = obj.numTestScores;
           testScores = new double[numTestScores];
           for (int i = 0; i < numTestScores; i++)
               testScores[i] = obj.testScores[i];   }

        // destructor
        ~StudentTestScores()
        {   delete [] testScores;   }

        // overloaded = operator
        const StudentTestScores operator=(const StudentTestScores &right)
        {
            if (this != &right)
            {
                delete [] testScores;
                studentName = right.studentName;
                numTestScores = right.numTestScores;
                testScores = new double[numTestScores];
                for (int i = 0; i < numTestScores; i++)
                    testScores[i] = right.testScores[i];
            }
            return *this;
        }

        // sets a specific test score's value
        void setTestScore(double score, int index)
        {   testScores[index] = score;  }

        // sets the student's name
        void setStudentName(string name)
        {   studentName = name; }

        // get the student's name
        string getStudentName()
        {   return studentName; }

        // get the number of test scores
        int getNumTestScores()
        {   return numTestScores;   }

        // get a specific test score
        double getTestScore(int index) const
        {   return testScores[index];   }
};
#endif

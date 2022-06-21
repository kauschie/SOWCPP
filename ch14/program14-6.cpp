#include <iostream>
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

// function prototypes
void displayStudent(StudentTestScores);

int main()
{

    // create a StudentTestScores object and assigns test scores.
    StudentTestScores student1("Kelly Thorton", 3);
    student1.setTestScore(100, 0);
    student1.setTestScore(95, 1);
    student1.setTestScore(80, 2);

    // create another StudentTestScores object with default test scores
    StudentTestScores student2("Jimmy Griffin", 5);

    // they should contain different data
    displayStudent(student1);
    displayStudent(student2);
    
    // assign student 1 object to the student 2 object 
    student2 = student1;

    // they should now contain the same data
    displayStudent(student1);
    displayStudent(student2);

    return 0;
}

void displayStudent(StudentTestScores s)
{
    cout << "Name: " << s.getStudentName() << endl;
    cout << "Test Scores: ";
    for (int i = 0; i < s.getNumTestScores(); i++)
        cout << s.getTestScore(i) << " ";
    cout << endl;
}



// specification file for CsStudent class
#ifndef CSSTUDENT_H
#define CSSTUDENT_H
#include "Student.h"

// constants for required hours
const int MATH_HOURS = 20;
const int CS_HOURS = 40;
const int GEN_ED_HOURS = 60;

class CsStudent : public Student
{
private:
  int mathHours;
  int csHours;
  int genEdHours;

public:
  // default constructor
  CsStudent() : Student()
  { mathHours = 0;
    csHours = 0;
    genEdHours = 0; }

    // constructor
  CsStudent(string n, string id, int year) :
    Student(n, id, year)
    { mathHours = 0;
      csHours = 0;
      genEdHours = 0; }

      // mutator
      void setMathHours(int mh)
      { mathHours = mh; }

      void setCsHours(int csh)
      { csHours = csh; }

      void setGenEdHours(int geh)
      { genEdHours = geh; }

      virtual int getRemainingHours() const;
};

#endif

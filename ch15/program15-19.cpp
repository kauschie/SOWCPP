#include <iostream>
#include "CsStudent.h"
using namespace std;

int main()
{
  // Create a CsStudent object for a student
  CsStudent student("Jennifer Haynes", "167W98337", 2006);

  // store values for math, comp sci and generel ed hours
  student.setMathHours(12); // student has taken 12 math hours
  student.setCsHours(20); // student has taken 20 CS hours
  student.setGenEdHours(40);  // student has taken 40 gen ed hours

  // display the number of remaining hours
  cout << "The student " << student.getName()
    << " needs to take " << student.getRemainingHours()
    << " more hours to graduate.\n";

  return 0;
}

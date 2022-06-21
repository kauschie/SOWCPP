// implementation of CsStudent.h
#include <iostream>
#include "CsStudent.h"
using namespace std;

int CsStudent::getRemainingHours() const
{
  int reqHours,     // total required hours
      remainingHours; // reminaing hours

      // calculate the required hours
      reqHours = MATH_HOURS + CS_HOURS + GEN_ED_HOURS;

      // calculate reminaing hours
      remainingHours = reqHours - (mathHours + csHours + genEdHours);

      return remainingHours;
}

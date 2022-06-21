59) 
    missing datatypes in Box(double w, l, h)
    copy constructor should be passing a reference variable

60)
    overloaded = operator should be:
        Circle operator=(Circle &right)
            { if (this != &right)
                {
                // same previous code
                return *this
                }
            }

61)
    overloaded + operator should be:
        void operator+(const Point& right)

62)
    Box is missing datatypes for l and h
    prefix++ operator should return Box and not void
    postfix++ operator should return Box and pass in dummy int param

63)
    Yard constructor needs to be capitalized
    conversion function doesn't need a return value

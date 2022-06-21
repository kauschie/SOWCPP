***********************************
            Inheritance
***********************************

    Concept:

        Inheritance allows a new class to be based on an old class
            -- the new class automatically inherits all the member vars and functions


        When one object is a specialized version of another object, there is an

                            "  is  a  "     Relationship

            Parent class    ~~~~>       Child class
            Base class      ~~~~>       Derived class


    ~~~~~~~~~~~~~~~~~~~~~~~~~
    Declaring a derived class
    ~~~~~~~~~~~~~~~~~~~~~~~~~


class Base
{
    private:                        // private members from base class stay private
        int x;                      // will only be available to the derived class if you use the base class's
    public:                         // member functions
        Base() { x = 0; }                   ///// Note: base constructors aren't inhereted
        baseSetFunc(int n) { x = n; }
};

class Derived : public Base             // DeriedClassName : AccessSpecifier BaseClassName
{
    private:
        int y;
    public:
        Derived() { y = 0; }            // public functions/variables are available to the derived class
        Derived(int z) { y = z; }
        int getVal() { return y; }
};

Derived d(5);
Base b(4);

d.baseSetFunc(10);          // works to set d.x = 10;
d.getVal()              // returns d.y which is 10
b.getVal();                 // error - cann't use class from derived class with base class


**************************************
  Protected Members and Class Access
**************************************

    Concept:

        Protected Members of a base class are like private members, but they may be accessed by derived classes

    * The base class access specification

                            vvvvvv

        class Derived : AccessSpecifier BaseClass

                   * determines how private, public and protected class members are accessed when
                            they are inherited by the derived class



    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    class access specification vs member access specification
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            Member access specification:
            ----------------------------
                        determines how members that are defined within the class are accessed

            Base class access specification:
            --------------------------------
                        determines how inherited members are accessed


------------------------------------------------------------------------------------------------------------
    Base Class Access       ||||
      Specification         ||||       How member of base class appear in derived class
------------------------------------------------------------------------------------------------------------
                            base    ->    derived              base    ->  derivedd       base  ->  derived
------------------------------------------------------------------------------------------------------------

    private         :     private  -> inaccessible      ;   Protected -> private    ;   Public -> private

    protected       :     private  -> inaccessible      ;   Protected -> protected  ;   Public -> protected

    public          :     private  -> inaccessible      ;   Protected -> protected  ;   Public -> public


------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------

        If the base clas access specification is left out of a declaration,
                the default is private

                ( eg )

        class Test : Grade





**********************************************************
 Constructors and Destructors in Base and Derived Classes
**********************************************************

    Concept:

        The base class's constructor is called before the derived class's constructor

        The destructor's are called in reverse order with the derived being called first and
                base being called after

// syntax  //

ClassName::ClassName(ParameterList) : BaseClassName(ArgumentList)

// End Syntax //

( eg )

class DerivedClass : public BaseClass
{
    public:
        DerivedClass() : BaseClass()     // Colon ( : ) followed by a function call to the base class CTOR
        {
            // code
        }
};


        //  You can also pass parameters like so:

( eg - inline in class definition)


Box(double w, double len, double h) : Rectangle(w, len)



( eg - outside the class definition)

Box : public Rectangle
{
    public:
        Box(double, double, double);        // notice that there no constructor call in prototype
};
Box::Box(double w, double len, double h) : Rectangle(w, len)
{                                       // call to base constructor occurs in function header
    height = h;
    volume = getArea() * h;
}


    ** base constructor is always executed before the derived class constructor


    If the base class has no default constructor, then the derived class must have a constructor
        that calls one of the base class constructors



  ~~~~~~~~~~~~~~~~~~~~~~~~~~~
   Constructor Inheritance
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~

        Derived classes can inherit some of the base class's constructors

                        Note:
                            Constructor's that cannot be inherited:
                            --------------------------------------
                            (1)  Default Constructor
                            (2)  Copy Constructor
                            (3)  Move Constructor


// "using" general syntax   \\

using BaseClassName::BaseClassName;             // can be used anywhere in the derived class

// end syntax   \\

class MyBase
{
    private:
        int ival;
        double dval;
    public:
        MyBase(int i)
        { ival = i; }
        MyBase(double d)
        { dval = d; }
};

class MyDerived : public MyBase
{
    private:
        string str;
    public:
        // now
        using MyBase::MyBase;           // using statement causes MyDerived to inherit
                                        // MyBase class's constructors

        MyDerived(string s)             // derived class can then have more constructors
        { str = s; }

        // previously
        MyDerived(int i) : MyBase(i)            // calls MyBase constructor and passes in i as the param
        {}

        MyDerived(double d) : MyBase(d)
        {}

};



oOo~~> Another Example:

    class Derived : Base
    {
        private:
            string str;
        public:
            using Base::Base;
            Derived(string s) : Base(0)
            { str = s; }
    };





           *Note: if derived class constructor has same parameter list as base class, it won't be inherited


    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     Redefining Base Class Functions
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        Concept:
            A base class member function may be redefined in a derived class

    * When a derived class' member function has the same name as the base class member function,
    *       it is said the derive class function redefines the base class function

    // ( eg from program15-7.cpp
    void setScore(double s)
    { rawscore = s;
        GradedActivity::setScore(rawScore * percentage); }  // calls baseclass's version of setScore func

        ** derived class function may call a base class function of the same name using this notation:

            BaseClassName::functionName(ArgumentList);




**************************
    Class Hierarchies
**************************

    Concept:

        A base class can also be derived from another class


class one
{
    // class one implementation
}

class two : public one              // base class for class three
{
    // class two implementation
}

class three : public two
{
    // class three implementation
}

        * be aware of what variables are inhereted with the access specifiers


*************************************************
    Polymorphism and Virtual Member Functions
*************************************************

    Concept:

        Polymorphism allows an object reference variable or an object pointer to reference
            objects of different types and to call the correct member functions, depending
            upon the type of object being referenced

    oOo~~>  C++ matches function calls with the correct function
        a process known as (((    binding      )))

        << static binding >>

            the process of matching a function call with a function at compile time

        << dynamic binding >>

            c++ determines at runtime which function to use


    eg)

    void displayGrade(GradedActivity &activity)     // because a GradedActivity obj was used
    {
        cout << activity.getScore() << endl;        // these function calls will be to the
        cout << activity.getLetterGrade() << endl;  // GradedActivity member functions
    }

Note:
def:  virtual function:
    you can pass in an object of another class that is inherited from GradedActivity
      (( eg ))

    FinalExam test;         // a FinalExam is a GradedActivity
    displayGrade(test)

    // care must be taken when using classes with redefined member functions
            the wrong function may be used due to (((   binding   )))

    ~~~~~~~~~~~~~~~~~~~~~~~~
    def:  virtual function:
    ~~~~~~~~~~~~~~~~~~~~~~~~

    a member function that is dynamically bound to function calls
            o   ( eg )  if a GradedActivity is responsible for the call, it uses the
                        GradedActivity::memberFunction()
            o   ( eg )  if a FinalExam obj is responisble for the call, it uses
                        FinalExam::memberFunction()

:::::::  syntax  :::::::::::

virtual char getLetterGrade() const;

    // tells compiler to expect getLetterGrade to be redefined in a derived class

    Notes:
        *   place virtual keyword in the functions declaration or prototype
        *   if defined outside class, do not place virtual keyword in function header


    :: polymorphism ::

        def: the ability to take many forms



    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Polymorphism requires references or pointers
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        * static binding will still take place if reference / pointers are not used
                even with the use of the keyword virtual
            ((( program15-12 and program15-13 )))




***************************
    Base Class Pointers
***************************

   * Pointers to a base class may be assigned the address of a derived class

   ( eg )

    GradedActivity * exam = new PassFailExam(100, 25, 70.0);

            // dynamically allocates PassFailExam object and assigns  its address
            // to exam, which is a GradedActivity Pointer

    cout << exam->getScore() << endl;
    cout << exam->getLetterGrade() << endl;


    * Base class pointers and references know ONLY about base class members

    suppose:

    class Base:                     then:
    {                       Base * bPtr = new Derived;
        public:
            xFunc()         bPtr->xFunc()       // valid
    };
    class Derived:
    {
        public:
            yFunc()         bPtr->yFunc()       // invalid
    };


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 is-a relationship doesn't work in reverse
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    -- cannot assign a pointer of a derived type to be a pointer of the base type

    ++ you CAN cast it

    ( eg )

    GradedActivity *gaPointer = new GradedActivity(88.0);
    // the following will not work
    FinalExam *fePointer = gaPointer;
    // this will work with limitations
    FinalExam *fePointer = static_cast<FinalExam *>(gaPointer);
    // derived class objects will compile but error at runtime
    cout << fePointer->getPointsEach() << endl;



    overridden functions are dynamically bound
            o (virtual functions)
    redefined functions are statically bound


**************************
   Virtual Destructors
**************************

    * compiler will perform static binding on destructor
            - this will lead to problems if base class pointers refrences a derived class object
            - if derived class has its own destructor, it will not execute when the obj is destroyed

    o   Base class destructors should be declared virtual for this reason

    ((( see program15-15.cpp )))

    Animal * myAnimal = new Dog;            // both the animal and dog constructors execute
    delete myAnimal                 // only the Animal destructor executes
                                    // can fix by declaring Animal class destructor as virtual
                                   ((( see program15-16.cpp )))

    virtual ~Dog()                          // the only change
    { cout << "running destructor\n"; }


    *   Any class that has a virtual member function, should have a virtual destructor
    *
    *   When a base class function is declared virtual
                o  All overridden version of the function in derived classes automatically become virtual
                o  declaring base class function ensures all derived versions are virtual

~~~~~~~~~~~~~~~~~~
 override keyword
~~~~~~~~~~~~~~~~~~
        * tells the compiler that the function is supposed to override a function in the base class
        * will cause a compiler error if the function does not actually override any functions

        ( eg )
        virtual void functionA(int arg) const override
            { cout << "This is Derivved::functionA" << endl; }

~~~~~~~~~~~~~~~~~~
  final keyword
~~~~~~~~~~~~~~~~~~
        * cannot be overridden in a base class

        ( eg )
        virtual void message() const final;


*******************************
     Abstract Base Classes
*******************************

    Concept:
        An ABC cannot be instantiated but other classes are derived from it.

    ::: pure virtual function :::
            - virtual member function of a base class that must be overridden

        * When a class contains a pure virtual function, it becomes an << abstract base class >>


        ( eg )

        virtual void showInfo() = 0;

            // the = 0 notation indicates that showInfo is a pure virtual function
            // pure virtual functions have no body or definition

        * compiler error if you attempt to define an object of an abstract base class


********************************
    Multiple Inheritance
********************************

  Concept:
    Multiple Inheritance is when a darived class has two or more base Classes


  consider:

  class Date
  {
    // code
  };

  class Time
  {
    // code
  };

  class DateTime: public Date, public Time    ** DETERMINES CALLING ORDER BELOW
  {

  };

  (( format: ))

  class DerivedClassName : AccessSpecification BaseClassName,
                          AccessSpecification BaseClassName2, etc

  Note:
  // constructor for DateTime Class
  DateTime::DateTime(args) : Time(args), Date(args)

      * the constructors are actually called in the order that their access
      specifiers appear in the class declaration

      because date is listed before time, it will always be called in that order

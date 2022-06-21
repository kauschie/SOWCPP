// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>      // bad_alloc exception
#include <cstdlib>  // exit()

using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr;    // to point to the allocated array
    int arraySize;  // # elements in the array
    void memError();    // handles memory allocation errors
    void subError();    // handles subscripts out of range

public:
    // default constructor
    SimpleVector()
    { aptr = 0; arraySize = 0;}

    // constructor declaration
    SimpleVector(int);

    // copy constructor declaration
    SimpleVector(const SimpleVector &);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size
    int size() const
        { return arraySize; }

    // Accessor to return a specific element
    T getElementAt(int position);

    // overloaded [] operator declaration
    T & operator[](const int &);
};

// constructor for simplevector class
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    // Allocate memory for the array
    try
    {
        aptr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }

    // Initialize the array
    for (int i = 0; i < arraySize; i++)
    {
        *(aptr+i) = 0;
    }
}

// copy constructor for the simplevector class
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // copy the array size
    arraySize = obj.arraySize;

    // allocate memory for the array
    aptr = new T [arraySize];
    if (0 == aptr)
        memError();

    // copy the elements of obj's array
    for (int i = 0; i < arraySize; i++)
    {
        *(aptr+i) = *(obj.aptr + i);
    }
}

// destructor for SimpleVector class
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize>0)
        delete [] aptr;
}

// memerror function. displays error and terminates prog
// when memory allocation fails
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

// suberror, displays error message and terms program
// when a subscript is out of range

template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

// getElementAt function. Arg is a subscript.
// this function returns the value stored at the subscript
// in the array
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

// overloaded [] operator. arg is a subscript
// this function returns a reference to the element
// in the array indexed by the subscript

template <class T>
T & SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        subError();
    }
    return aptr[sub];
}
#endif

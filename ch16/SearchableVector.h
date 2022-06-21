#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
    // default constructor
    SearchableVector() : SimpleVector<T>()
        { }
    // constructor
    SearchableVector(int size) : SimpleVector<T>(size)
        { }

    // copy constructor
    SearchableVector(const SearchableVector &);

    // accessor to find an item
    int findItem(const T);
};

// copy constructor
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector & obj) :
                        SimpleVector<T>(obj.size())
{
    for (int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

// findItem function
// search for item. if item is found
// the subscript is returned. otherwise -1 is returned

template <class T>
int SearchableVector<T>::findItem(const T item)
{
    for (int count = 0; count <= this->size(); count++)
    {
        if (getElementAt(count) == item)
            return count;
    }
    return -1;
}

#endif /* end of include guard: SEARCHABLEVECTOR_H */

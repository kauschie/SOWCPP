#include <iostream>
using namespace std;

class Tree
{
    private:
        static int objectCount;     // static member variable
    public:
        Tree()
        {
            objectCount++;
        }

        int getObjectCount() const { return objectCount; }

};

// Definition of the static member variable, written outside the class

int Tree::objectCount = 0;

main()
{
    // define 3 tree objects
    Tree oak;
    Tree elm;
    Tree pine;

    cout << "We have " << pine.getObjectCount() << " trees in our program!\n";
    cout << "We have " << elm.getObjectCount() << " trees in our program!\n";
    cout << "We have " << oak.getObjectCount() << " trees in our program!\n";

    return 0;
}

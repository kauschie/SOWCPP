#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Person
{
    private:
        char* name;
    public:
        Person()
        {   cout << "*** default constructor ***\n";
            name = nullptr; }

        Person(char *n)
        { cout << "*** parameterized constructor ***\n";
            name = new char[strlen(n) + 1];
            strcpy(name, n); }

        Person(Person&& temp)
        {
            name = name.temp;
            temp.name = nullptr;

        }
        // copy constructor
        Person(const Person& obj)
        { cout << "*** copy constructor ***\n";
            name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name); }

        ~Person()
        { cout << "*** destructor ***\n";
            delete [] name; }

        Person& operator=(Person&& right)
        {
            if (this != &right)
            {
                swap(name, right.name);
            }
            return *this;
        }

        Person& operator=(const Person & right)
        { cout << "*** assignment operator ***\n";
            if (this != &right)
            {
                if (name != nullptr)
                    delete [] name;
                name = new char[strlen(right.name) + 1];
                strcpy(name, right.name);
            }

            return *this;
        }

        char* getName() const
        {   return name;    }
};

Person makePerson();
void displayPerson(Person);

int main()
{
    Person person;
    person = makePerson();
    displayPerson(person);

    return 0;
}

Person makePerson()
{
    char s[] = "Will MacKenzie";
    Person p(s);
    return p;
}

void displayPerson(Person p2)
{
    cout << p2.getName() << endl;
}

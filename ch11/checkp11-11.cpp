// checkpoints starting at 11-11
// michael kausch
// 11/9/21
#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int width;
};

// function prototypes

void showRect(Rectangle r); // checkp 11.11
void getRect(Rectangle &);  // checkp 11.12
Rectangle getRect();


int main()
{
    Rectangle myRec = getRect();
    Rectangle *rPtr = &myRec;       // checkp 11.14

    // checkp 11.15
    // rptr->width is equivalent to what other statement
    cout << (*rptr).width << endl;      // answer B

    return 0;
}

// checkp 11.11
void showRect(Rectangle r)
{
    cout << "Length: " << r.length << endl;
    cout << "Width: " << r.width << endl;
}
 // checkp 11.12
void getRect(Rectangle &r)
{
    cout << "Length: ";
    cin >> r.length;
    cout << "Width: ";
    cin >> r.width;
}


// checkp 11.13
Rectangle getRect()
{
    Rectangle r;
    cout << "Length: ";
    cin >> r.length;
    cout << "Width: ";
    cin >> r.width;
    return r;
}



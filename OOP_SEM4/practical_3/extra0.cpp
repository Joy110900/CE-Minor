/*
1. Create class rectangle
2. Take 2 params -> length, breadth
3. Create a method to compare area of 2 rectangles
4. Print biggest area
*/
#include <iostream>

using namespace std;

class rect
{
    float length, breadth;
    public:
    void enter_l_b();
    void cmp_area(rect, rect);
};

int main()
{
    rect a, b;
    a.enter_l_b();
    b.enter_l_b();
    a.cmp_area(a, b);
}

void rect:: enter_l_b()
{
    cout << "\nEnter length of the rectangle: ";
    cin >> length;

    cout << "\nEnter breadth of the rectangle: ";
    cin >> breadth;
}

void rect:: cmp_area(rect a, rect b)
{
    float aa, ab;
    aa = a.length*a.breadth;
    ab = b.length*b.breadth;
    if(aa > ab)
        cout << "\nBiggest area = " << aa;

    else
        cout << "\nBiggest area = " << ab;
}
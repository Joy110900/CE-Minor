#include <iostream>

using namespace std;

struct Rectangle
{
    float length, breadth;
};

int main()
{
    float area, perim, area1, perim1;
    Rectangle r1, r2;

    cout << "Enter length of first rectangle: ";
    cin >> r1.length;

    cout << "Enter breadth of first rectangle: ";
    cin >> r1.breadth;

    cout << "Enter length of second rectangle: ";
    cin >> r2.length;

    cout << "Enter breadth of second rectangle: ";
    cin >> r2.breadth;

    cout << "Area of first Rectangle is = " << r1.length*r1.breadth << endl;
    cout << "Perimeter of first Rectangle is = " << 2*(r1.length+r1.breadth) << endl;

    cout << "Area of second Rectangle is = " << r2.length*r2.breadth << endl;
    cout << "Perimeter of second Rectangle is = " << 2*(r2.length+r2.breadth) << endl;

    return 0;
}

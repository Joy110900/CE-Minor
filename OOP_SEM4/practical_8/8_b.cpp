/*
Create a base class called Shape. Use this class to store two double type values that could be used
to compute the area of figures. Derive two specific class called Triangle and Rectangle 
from the baseshape. Add to the base class, a member function get_data() to initialize the      
base class data members and another member function display_area() to compute and display area of figures. 
Make display_area as a virtual function and redefine this function in derived classes to suit
their requirements. Using these three classes, design a program that will accept dimensions of a 
triangle or rectangle interactively and display the area.
*/
#include <iostream>

using namespace std;

class shape;
class triangle;
class rectangle;

class shape
{
    protected:
    double len, breadth;

    public:
    void get_data()
    {
        cout << "\nEnter 1st Dimension: ";
        cin >> len;
        cout << "\nEnter 2nd Dimension: ";
        cin >> breadth;
    }
    virtual void area()
    {

    }
};

class traingle: public shape
{
    public:
    void area()
    {
        cout << "\nArea of Triangle = " << double(0.5 * len * breadth);
    }
};

class rectangle: public shape
{
    public:
    void area()
    {
        cout << "\nArea of Rectangle = " << double(len * breadth * 1.0);
    }
};

int main()
{
    int n;
    cout << "\n1. Triangle";
    cout << "\n2. Rectangle";

    cout << "\nEnter your choice: ";
    cin >> n;

    if (n == 1)
    {
        traingle t;
        t.get_data();
        t.area();
    }

    if (n == 2)
    {
        rectangle t;
        t.get_data();
        t.area();
    }

    return 0;
}
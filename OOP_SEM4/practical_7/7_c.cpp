/*
 Define a class Figure which initialize the two dimensions, i.e. dim1 and  dim2. 
 Define the  two classes circle  and  rectangle which calculates the area of the respective dimensions. 
 With the help of pointer to the base class call the function of both the derived classes.
*/

#include <iostream>

using namespace std;

class rectangle;
class circle;

class figure
{
    public:
    int dim1, dim2;

    void get_dim1()
    {
        cout << "\nEnter value for dim1: ";
        cin >> dim1;
    }

    void get_dim2()
    {
        cout << "\nEnter value for dim2: ";
        cin >> dim2;
    }

    virtual void area()
    {

    }
};

class rectangle: public figure
{
    public:
    void area()
    {
        cout << "\nArea of rectangle is :" << dim1*dim2;
    }
};

class circle: public figure
{
    public:
    void area()
    {
        cout << "\nArea of circle is: " << 3.1415*float(dim1)*float(dim1);
    }
};

int main()
{
    figure* f;
    rectangle r;
    circle c;

    f=&r;
    f -> get_dim1();
    f -> get_dim2();
    f -> area();
    
    f =&c;
    f -> get_dim1();
    f -> area();

    return 0;
}
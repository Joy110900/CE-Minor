/*
 Define a class Figure which initialize the two dimensions, i.e. dim1 and  dim2. 
 Define the  two classes circle  and  rectangle which calculates the area of the respective dimensions. 
 With the help of pointer to the base class call the function of both the derived classes.
*/

#include <iostream>
using namespace std;

class rectangle;

class figure
{
    public:
    virtual void pf()
    {
        cout << "\nThis is the base class.\n";
    }
};

class rectangle: public figure
{
    public:
    void pf()
    {
        cout << "\nThis is derived class\n";
    }
};

int main()
{
    figure* f;
    rectangle r;

    f=&r;
    f -> pf();

    return 0;
}
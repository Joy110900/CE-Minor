/*
Create a  class Complex. The  class should enable operations on complex  numbers. Overload multiplication operation to enable multiplication of two complex numbers in algebra.Hint : Multiply (1 + 2i) and (2 - 3i)Answer:(Here i2=-1)(1 + 2i)(2 - 3i) = (1 × 2) + (1× (-3i)) + (2i × 2) + (2i× (-3i)) = 2 - 3i + 4i + 6 = 8 + i
*/

#include <iostream>

using namespace std;

class complex
{
    public:
    complex(int,int);
    int r,i;
    complex operator *(complex a);
    void display();
};

int main()
{  
    complex a(1,2),b(2,-3),c(1,1);
    c = a*b;
    c.display();
    return 0;
}

complex:: complex(int a=1,int b=1)
{
    r = a;
    i = b;
}

complex complex::operator*(complex a)
{
    complex l;
    l.r = (r*a.r) + -1*(a.i*i);
    l.i = (r*a.i) + (a.r*i);
    return l;
}

void complex:: display()
{
    cout << endl << r << " + i" << i << endl; 
}
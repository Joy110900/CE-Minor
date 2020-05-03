/*
 Write a Program  to find Maximum of three floating point numbers
(should have double type variable also), three integers, three characters .
*/

#include <iostream>

using namespace std;

template <typename a>
void max3(a n1, a n2, a n3)
{
    a max;

    if(n1 > n2)
    {
        if(n1 > n3)
            max = n1;

        else
            max = n3;
    }

    else
    {
        if(n2 > n3)
            max = n2;

        else
            max = n3;
    }

    cout << "\nmax = " << max << endl;
}

int main()
{
   max3('a','s','w');
   max3(3.14, 4.21, 3.15);
   max3(1,3,6);
}

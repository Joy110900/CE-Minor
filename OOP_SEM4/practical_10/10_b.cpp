/*
Write a program to find factorial of a given integer number. 
Throw multiple exceptions and define multiple catch statements to
handle negative number andout of memory exception. 
Negative number exception thrown if given number is negative value and 
out of memory exception is thrown if the given number is greater than 20.
*/
#include <iostream>

using namespace std;

int main()
{
    int n,i,f=1;

    cout << "\n Enter a Number to find factorial: ";
    cin >> n;
    
    try
    {
        if(n > 0 && n < 20)
        {
            for(i=1; i<=n; i++)
                f *= i;
            cout << "Factorial = " << f << endl;
        }
        
    else if(n < 0)
        throw (0);
        
    if(n > 20)
        throw(1.0);
    }
        
    catch(int i)
    {
        cout<<"\n You enterd a Negative Number.\n";
    }

    catch(double i) 
    {
        cout<<"\nThe code ran out of memory.\n";
    }
}
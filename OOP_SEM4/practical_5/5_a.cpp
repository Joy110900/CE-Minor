/*
Create a  class MyString which has members as under
Data members : 
1)To store string length   
2)To store the string itself 
Member functions : 
1)Default constructors
2)Another parameterized Constructor which initialize with string constant 
3)A copy constructors 
4)A member function to reverse the case of the string          
5)A member function to display desired string object.          
6)Provide destructor to destroy the constructor.
*/

#include <iostream>

using namespace std;

void changecase(string &a)
{
    int l = a.length();

    for(int i=0; i < l; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
            a[i] = a[i] - 32;

        else
            a[i] = a[i] + 32;
    } 
}

class mystring
{
    string s;
    int l;
    public:
    mystring()
    {
        s = '0';
        l = 1;
    }
    mystring(string a)
    {
        s = a;
        l = s.length();
    }
    mystring(mystring &a)
    {
        s = a.s;
        l = a.l;   
    }
    void changecase()
    {
        int l = s.length();

         for(int i=0; i < l; i++)
            {
                if(s[i] >= 'a' && s[i] <= 'z' && s[i] != ' ')
                    s[i] = s[i] - 32;

                else if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != ' ')
                    s[i] = s[i] + 32;
            }
    }
    void display()
    {
        cout << endl << "String is -> " << s << endl <<"Length = " << l;
    }

    ~ mystring()
    {
        s = '\0';
        l = 0; 
    }
};

int main()
{
    mystring a("My name is Joy");
    a.display();
    a.changecase();
    a.display();
    return 0;
}
/*
Define a class NewString which stores string.
Overload == operator to  compare two strings stored in NewString objects.
*/

#include <iostream>

using namespace std;

class newstring
{
    private:
    string s;

    public:
    newstring(string a)
    {
        s = a;
    }

    void operator ==(newstring a)
    {   
        if(s.compare(a.s) == 0)
           cout << endl << "The strings are Equal";
        else
          cout << endl << "The strings are not equal";
    }
};

int main()
{
    newstring a("hello"), b("hi");
    a == b;
    return 0;
}
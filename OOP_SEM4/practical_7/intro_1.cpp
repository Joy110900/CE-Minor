/*
An educational institution wishes to maintain adatabase of its employees. 
The database is dividedinto  a  number of classes whose hierarchical relationships are as follows:
Staff (code, name) is the base class;
which in turn has Teacher(subject, publication), Typist (speed)and Officer(grade) as its childclasses.
The Typist againhas Regular() and Casual (Daily Wages) as its childclasses. 
Note that the information given in bracketsspecifies the  minimuminformation required foreach class. 
Specify all classes and define functionsto create the database and retrieve information asand when needed
*/
#include <iostream>

using namespace std;

class B;
class C;

class A
{
    protected:
    int a = 1;
    public:
    int pa()
    {
        cout << a << endl;
    }
};

class B: protected A
{
    public: 
    void pb()
    {
        cout << a << endl;
    }
};

class C: protected B
{
    public: 
    void pc()
    {
        cout << a << endl;
    }
};

int main()
{
    A a;
    B b;
    C c;
    c.pc();
    return 0;
}
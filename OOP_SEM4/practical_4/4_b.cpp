/*
Create two classes having name Student and Professor which stores student and professor information respectively.
Make a friend function comm_name() which finds the common name from both the classes.
*/
#include <iostream>

using namespace std;

class student;
class professor;

class student
{
    private:
    string name;

    public:
    void get_name();
    friend void comm_name(student, professor);
};

class professor
{
    private:
    string name;

    public:
    void get_name();
    friend void comm_name(student, professor);
};

int main()
{
    int sn = 3, pn =4;
    student i[sn];
    professor j[pn];

    for(int i=0; i < sn; i++)
    {
        for(int j=0; j < pn; j++)
        {
            
        }
    }

    return 0;
}

void comm_name(student, professor)
{

}

void student:: get_name()
{
    getline(cin, name);
}

void professor:: get_name()
{
    getline(cin, name);
}
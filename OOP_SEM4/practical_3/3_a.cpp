/*
 Define a class student having members as stu_id, name, and marks in sub1, sub2 & sub3 Write a C++ program to get information of n students and display them using appropriate member functions.
*/

#include <iostream>

using namespace std;

class student
{
    int stu_id, m1, m2, m3;
    string name;
    public:
    void enter_name();
    void enterID();
    void enter_marks();
    void show_marks();
};

int main()
{
    int n;
    cout << "\nEnter No. of Students: ";
    cin >> n;
    student s[n];
    for(int i=0; i < n; i++)
    {
        s[i].enter_name();
        s[i].enterID();
        s[i].enter_marks();
        s[i].show_marks();
    }
    return 0;
}

void student:: enter_name()
{
    cout << "\nStudent Name: ";
    cin >> name;
}

void student:: enterID()
{
    cout << "\nStudent ID: ";
    cin >> stu_id;
}

void student:: enter_marks()
{
    cout << "\nEnter Marks of Subject 1: ";
    cin >> m1;

    cout << "\nEnter Marks of Subject 2: ";
    cin >> m2;

    cout << "\nEnter Marks of Subject 3: ";
    cin >> m3;
}

void student:: show_marks()
{
    cout << "\n Subject 1 Marks = " << m1;
    
    cout << "\n Subject 2 Marks = " << m2;

    cout << "\n Subject 3 Marks = " << m3;
}
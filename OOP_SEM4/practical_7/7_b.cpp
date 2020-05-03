/*
Consider a class student having roll number and supporting methods to get and print the roll number, 
this class will be inherited by two different classes: 
test and score that gives the marks in two subjects and marks in sports category respectively. 

In final class result (inherits class test and score) find the total marks and 
print all the data (roll number, marks in two subjects, marks in sports and total marks). 
Use the concept of virtual base class.
*/
#include <iostream>

using namespace std;

class student
{
    protected:
    int rollno;

    public:
    void getroll()
    {
        cout << "\nEnter Student Roll No: ";
        cin >> rollno;
    }
    void disproll()
    {
    cout << "\nRoll No.: " << rollno;
    }
}s;

class test : virtual public student
{
    protected:
    int mark1;
    int mark2;

    public:
    void getmarks()
    {
        cout << "\nEnter 1st Subject Marks: ";
        cin >> mark1;
        cout << "\nEnter 2nd Subject Marks: ";
        cin >> mark2;
    }
    void dispmarks()
    {
        cout << "\nThe 1st Subject Marks: " << mark1;
        cout << "\nThe 2nd Subject Marks: " << mark2;
    }

    int totmarks()
    {
        return (mark1 + mark2);
    }
}t;

class score : virtual public student
{
    protected:
    int score1;
    int score2;

    public:
    void getscore()
    {
        cout << "\nEnter the 1st Game Score: ";
        cin >> score1;
        cout << "\nEnter the 2nd Game Score: ";
        cin >> score2;
    }
    void dispscore()
    {
        cout << "\n1st Game Score: " << score1;
        cout << "\n2nd Game Score: " << score1;    
    }

    int totscore()
    {
        return (score1 + score2);
    }
}c;

class result:public test,public score
{
    public:
    void show_score()
    {
        cout << "\nTotal Score: " << totscore();
    }
    void show_marks()
    {
        cout << "\nTotal Marks: " << totmarks();
    }
}r;

int main()
{
    int n;
    
    while(1)
    {
        cout << "\n1.Data";
        cout << "\n2.Display";
        cout << "\n3.Exit";

        cout << "\nEnter your choice: ";
        cin >> n;

        if (n == 1)
        {
            s.getroll();
            cout << "\nEnter the Region of Scoring";
            cout << "\n1.Test";
            cout << "\n2.Sports";
            cout << "\nEnter your choice: ";
            cin >> n;
            if(n == 1)
                t.getroll();
            else
                c.getscore();
        }

        else if (n == 2)
        {
            s.disproll();
            r.show_score();
            r.show_marks();
        }

        else if (n == 3)
            break;
    }

    return 0;
}
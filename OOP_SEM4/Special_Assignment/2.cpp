/*
Write a C++ program to create a base class called STUDENT with private data members 
Name, Roll Number & Age and using inheritance create 
classes UG and PG having members as Semester, Fee and Stipend. 
Enter the data of 5 students and find the average age per semester for all UG and PG students separately.
*/
#include <iostream>

using namespace std;

class student;
class ug;
class pg;

class student
{
    private:
    string name;
    int age, roll;

    public:
    void get_basic_info()
    {
        cout << "\nEnter your name: ";
        cin >> name;

        cout << "\nEnter your Roll no.: ";
        cin >> roll;

        cout << "\nEnter your age: ";
        cin >> age;
    }

    int get_age()
    {
        return age;
    }

    string get_name()
    {
        return name;
    }

    int get_roll()
    {
        return roll;
    }
};

class ug: public student
{
    private:
    int sem, stipend, fee;

    public:
    void get_info()
    {
        cout << "\nEnter your Semester: ";
        cin >> sem;

        cout << "\nEnter youer stipend: ";
        cin >> stipend;

        cout << "\nEnter your fee: ";
        cin >> fee;
    }

    void disp_info()
    {
        cout << "\n----------------------------";
        cout << "\nUG STUDENT INFORMATION";
        cout << "\nName: " << get_name();
        cout << "\nAge: " << get_age();
        cout << "\nRoll No.: " << get_roll();
        cout << "\nSemester: " << sem;
        cout << "\nStipend: " << stipend;
        cout << "\nFee: " << fee;
        cout << "\n----------------------------";
    }
};

class pg: public student
{
    private:
    int sem, stipend, fee;

    public:
    void get_info()
    {
        cout << "\nEnter your Semester: ";
        cin >> sem;

        cout << "\nEnter youer stipend: ";
        cin >> stipend;

        cout << "\nEnter your fee: ";
        cin >> fee;
    }

    void disp_info()
    {
        cout << "\n----------------------------";
        cout << "\nPG STUDENT INFORMATION";
        cout << "\nName: " << get_name();
        cout << "\nAge: " << get_age();
        cout << "\nRoll No.: " << get_roll();
        cout << "\nSemester: " << sem;
        cout << "\nStipend: " << stipend;
        cout << "\nFee: " << fee;
        cout << "\n----------------------------";
    }
};

int main()
{
    ug u[5];
    pg s[5];
    int ug_age=0, pg_age=0;

    //Get info for UG students
    for(int i=0; i<5; i++)
    {
        cout << "\nUG students please enter your information:\n";
        u[i].get_basic_info();
        u[i].get_info();
        u[i].disp_info();
        ug_age += u[i].get_age();
    }

    //Get info for PG students
    for(int i=0; i<5; i++)
    {
        cout << "\nPG students please enter your information:\n";
        s[i].get_basic_info();
        s[i].get_info();
        s[i].disp_info();
        pg_age += s[i].get_age();
    }

    cout << "\nAverage age for students in UG = " << float(ug_age/5.0);
    cout << "\nAverage age for students in PG = " << float(pg_age/5.0) << endl;

    return 0;
}
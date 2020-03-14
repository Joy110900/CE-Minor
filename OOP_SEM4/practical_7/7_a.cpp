/*
An educational institution wishes to maintain a database of its employees. 
The database is divided into  a  number of classes whose hierarchical relationships are as follows:
Staff (code, name) is the base class;
which in turn has Teacher(subject, publication), Typist (speed)and Officer(grade) as its childclasses.
The Typist again has Regular() and Casual (Daily Wages) as its childclasses. 
Note that the information given in brackets specifies the  minimumin formation required foreach class. 
Specify all classes and define functionsto create the database and retrieve information asand when needed
*/

#include <iostream>

using namespace std;

class teacher;
class typist;
class officer;
class regular;
class casual;

class staff
{
    public:
    string code, name;
    void get_basic_info()
    {
        cout << endl << "Enter your name: ";
        cin >> name;
        cout << endl << "Enter your code: ";
        cin >> code;
    }
    void display_basic_info()
    {
        cout << endl << "Name: " << name << endl << "Code: " << code << endl;
    }
};

class teacher: public staff
{
    public:
    string sub, publication;
    void get_teacher_info()
    {
        cout << endl << "Enter your subject name: ";
        cin >> sub;
        cout << endl << "Enter your publication name: ";
        cin >> publication;
    }
    void display_teacher_info()
    {
        cout << endl << "Subject: " << sub << endl << "Publication: " << publication << endl;
    }
};

class typist: public staff
{
    public:
    int speed;
    void get_typist_info()
    {
        cout << endl << "Enter your typing speed in wpm: ";
        cin >> speed;
    }
    void display_typist_info()
    {
        cout << endl << "WPM: " << speed << endl;
    }
};

class officer: public staff
{
    public:
    string grade;
    void get_officer_info()
    {
        cout << endl << "Enter your grade: ";
        cin >> grade;
    }
    void display_officer_info()
    {
        cout << endl << "Grade: " << grade << endl;
    }
};

class regular: public typist
{
    public:
    int salary;
    void get_regular_typist_info()
    {
        cout << endl << "Enter your Salary: ";
        cin >> salary;
    }
    void display_regular_typist_info()
    {
        cout << endl << "Salary: " << salary << endl;
    }
};

class casual: public typist
{
    public:
    int daily_wages;
    void get_casual_typist_info()
    {
        cout << endl << "Enter your daily wages: ";
        cin >> daily_wages;
    }
    void display_casual_typist_info()
    {
        cout << endl << "Daily Wages: " << daily_wages << endl;
    }
};

int main()
{
    int in;
    cout << endl << "1: Teacher";
    cout << endl << "2: Typist";
    cout << endl << "3: Officer";

    cout << endl << "Enter your choice: ";
    cin >> in;

    if(in == 1)
    {
        teacher t;
        t.get_basic_info();
        t.get_teacher_info();

        t.display_basic_info();
        t.display_teacher_info();
    }

    else if (in ==2)
    {
        int inp;
        cout << endl << "1: Casual Typist";
        cout << endl << "2: Regular Typist";

        cout << endl << "Enter your choice: ";
        cin >> inp;

        if(inp == 1)
        {
            casual cty;
            cty.get_basic_info();
            cty.get_typist_info();
            cty.get_casual_typist_info();
            
            cty.display_basic_info();
            cty.display_typist_info();
            cty.display_casual_typist_info();
        }

        else if (inp == 2)
        {
            regular rty;
            rty.get_basic_info();
            rty.get_typist_info();
            rty.display_regular_typist_info();

            rty.display_basic_info();
            rty.display_typist_info();
            rty.display_regular_typist_info();
        }

        else
        {
            cout << "Please enter proper choice.";
        }
    }

    else if(in == 3)
    {
        officer o;
        o.get_basic_info();
        o.get_officer_info();

        o.display_basic_info();
        o.display_officer_info();
    }
    
    else
    {
        cout << "Please enter proper choice.";
    }

    return 0;
}
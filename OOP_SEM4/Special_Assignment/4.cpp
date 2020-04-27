/*
Create a class TIME that has separate integer data members for Hour, Minutes and Seconds.  
Initialize these members to 0 using default constructor and to fixed values using parameterized constructor.  
Create a member functions to display it, in 11:59:59 format and to add two objects of type TIME passed as arguments. 
*/
#include <iostream>

using namespace std;
class Time;

class Time
{
    private:
    int hour, min, sec;

    public:
    Time()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }

    Time(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }

    void setTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }

    void addtime(Time a, Time b)
    {
        int h=0, m=0, s=0;
        s = a.sec + b.sec;
        if (s>59)
        {
            m += 1;
            s -= 60;
        }
        m = a.min + b.min;
        if (m>59)
        {
            h += 1;
            m -= 60;
        }
        h = a.hour + b.hour;
        cout << "\n" << h << ":" << m << ":" << s << endl;

    }

    void disp()
    {
        cout << "\n" << hour << ":" << min << ":" << sec << endl;
    }
};

int main()
{
    Time t1, t2(4,32,45);
    cout << "\nTime intialised\n";
    cout << "\nT1 default constructor called:\n";
    t1.disp();
    cout << "\nT2 parameterized constructor called:\n";
    t2.disp();
    
    t1.setTime(6,53,30);
    cout << "\nTime T1 set to 6:53:30\n";
    t1.disp();
    t2.disp();

    cout << "\nAdding both times:\n";
    t1.addtime(t1, t2);

    return 0;
}
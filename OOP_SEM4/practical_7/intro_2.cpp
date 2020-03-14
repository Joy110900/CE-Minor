#include <iostream>

using namespace std;

class current_acc;
class savings_acc;

class bank
{
    public:
    string name;
    int code;
    bank()
    {
        name = "Unknown";
        code = 0;
    }
    bank(string s, int b)
    {
        name = s;
        code= b;
    }
};

class current_acc: public bank
{
    private:
    int bal;
    int min = 500;
    public:
    current_acc(int a, bank a)
    {
        if(a < min)
        {
            cout << "Balance should be minimum of Rs. 500";
        }

        else
            bal = a;
    }
    void withdraw(int a)
    {
        if(bal -= a < min)
            cout << "Can't withdraw because balance lower than minimum balance\n";
        else
            bal -= a;
    }

    void deposit(int a)
    {
        bal += a;
    }

    void display()
    {
        cout << "Bank Name - " << name << endl;
        cout << "Bank Code - " << code << endl;
        cout << "Balance - " << bal;
    }
};

class savings_acc: public bank
{
    private:
    int bal;
    int min = 1500;
    public:
    savings_acc(int a, bank b)
    {
        if(a < min)
        {
            cout << "Balance should be minimum of Rs. 500\n";
        }

        else
            bal = a;
    }
    void withdraw(int a)
    {
        if(bal -= a < min)
            cout << "Can't withdraw because balance lower than minimum balance\n";
        else
            bal -= a;
    }

    void deposit(int a)
    {
        bal += a;
    }

    void display()
    {
        cout << "Bank Name - " << name << endl;
        cout << "Bank Code - " << code << endl;
        cout << "Balance - " << bal << endl;
    }
};

int main()
{
    bank bob("Bank of Baraoda", 567);
    current_acc a(2400, bob);
    savings_acc s(3000, bob);
    s.display();
    return 0;
}
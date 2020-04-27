/*
Define a class Bank_Account with Current and Saving bank accounts as its  derived  classes.  
Class  Bank_Account  should  have  following  data members:  
Account_Number, Name, Balance_Amount  and  
Member Functions: to Initialize the value, to Deposite and Withdraw amount after checking the minimum balance.
*/
#include <iostream>

using namespace std;

class bank_acc;
class current_acc;
class savings_acc;

class bank_acc
{
    public:
    int number, balance;
    static const int min_bal=1500;
    string name;
    void get_info()
    {
        cout << "\nPlease enter your Name: ";
        cin >> name;

        cout << "\nPlease enter your Account Number: ";
        cin >> number;
        
        while(1)
        {
            cout << "\nPlease enter your Bank Balance: ";
            cin >> balance;
            if (balance < 1500)
                {
                    cout << "\nBalance should be greater than minimum balance which is " << min_bal;
                    cout << "\nPlease Re-enter your balance.\n";
                }

            else
                break;
        }
    }

    void withdraw()
    {
        int a;
        while(1)
        {
            cout << "\nEnter amount you want to withdraw from your account: ";
            cin >> a;
            if ((balance-a) < min_bal)
            {
                cout << "\nCannot withdraw if acount balance gets less than minimum balance.\n";
                cout << "Please enter other amount.\n";
            }

            else 
            {
                balance -= a;
                cout << "\nBalance after withdrawal = " << balance;
                break;
            }
        }
    }

    void deposit()
    {
        int a;
        cout << "\nEnter amount you want to deposit in your account: ";
        cin >> a;
        balance += a;
        cout << "\nBalance after deposit = " << balance;
    }

};

class current_acc: public bank_acc
{
    public:
    void show_info()
    {
        cout << "\n---------------------";
        cout << "\nCurrent Account Details:";
        cout << "\nAccount Number: " << number;
        cout << "\nAccount Name: " << name;
        cout << "\nAccount Balance: " << balance;
        cout << "\n---------------------\n";
    }
};

class savings_acc: public bank_acc
{
    public:
    void show_info()
    {
        cout << "\n---------------------";
        cout << "\nSavings Account Details:";
        cout << "\nAccount Number: " << number;
        cout << "\nAccount Name: " << name;
        cout << "\nAccount Balance: " << balance;
        cout << "\n---------------------\n";
    }
};

int main()
{   
    int a;
    while (1)
    {
        cout << "\nEnter 1 to create Current Account or 2 to create Savings Account:\n";
        cin >> a;
        if (a == 1)
        {
            current_acc c;
            c.get_info();
            while (1)
            {
                cout << "\nEnter 1 to withdraw money or 2 to deposit money:\n";
                cin >> a;
                if (a == 1)
                {
                    c.withdraw();
                    break;
                }
                else if (a == 2)
                {
                    c.deposit();
                    break;
                }
                else
                    cout << "\nPlease enter 1 or 2 only.\n";
            }
            c.show_info();
            break;
        }

        else if (a == 2)
        {
            savings_acc s;
            s.get_info();
            while (1)
            {
                cout << "\nEnter 1 to withdraw money or 2 to deposit money:\n";
                cin >> a;
                if (a == 1)
                {
                    s.withdraw();
                    break;
                }
                else if (a == 2)
                {
                    s.deposit();
                    break;
                }
                else
                    cout << "\nPlease enter 1 or 2 only.\n";
            }
            s.show_info();
            break;        
        }
        
        else 
            cout << "\nPlease enter 1 or 2 only.";
    }
    return 0;
}
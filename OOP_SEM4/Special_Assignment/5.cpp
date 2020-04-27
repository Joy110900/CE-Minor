/*Define a class named ‘Train’ having data members 
Train Number, Source, Destination, Journey date, Capacity &  
member functions to initialize members, to input train data & to display data. 
Also create a friend function to display whether source & destination of 
two objects of class Train are same or not.*/ 
#include <iostream>

using namespace std;

class train
{
    private:
    int num, capacity;
    string src, dest, date; 

    public:
    void get_train_info()
    {
        cout << "\nPlease enter Train number: ";
        cin >> num;

        cout << "\nPlease enter capacity: ";
        cin >> capacity;

        cout << "\nPlease enter Journey date in dd/mm/yyyy format: ";
        cin >> date;

        cout << "\nPlease enter Source: ";
        cin >> src;

        cout << "\nPlease enter Destination: ";
        cin >> dest;
    }

    void disp_train_info()
    {
        cout << "\n----------------------";
        cout << "\nTrain Number: " << num;
        cout << "\nCapacity: " << capacity;
        cout << "\nJourney date: " << date;
        cout << "\nFrom: " << src;
        cout << "\nTo: " << dest;
        cout << "\n----------------------";
    }

    friend void src_dest_cmp(train, train);
};

void src_dest_cmp(train a, train b)
    {
        if (a.src == b.src and a.dest == b.dest)
            cout << "\nBoth the trains have same source and destination\n";

        else if (a.src == b.src)
            cout << "\nBoth the trains have same source but different destination\n";

        else if (a.dest == b.dest)
            cout << "\nBoth the trains have same destination but different source\n";

        else
            cout <<"\nSource and destination of the trains are not same\n";
    }

int main()
{
    train a, b;
    cout << "\nEnter information for 1st train:\n";
    a.get_train_info();
    a.disp_train_info();
    cout << "\nEnter information for 2nd train:\n";
    b.get_train_info();
    b.disp_train_info();
    src_dest_cmp(a, b);
    return 0;
}
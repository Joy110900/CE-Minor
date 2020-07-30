#include <iostream>

using namespace std;

//Declaring two functions to swap the value of the arguments passed in it.
//One function will called by value and other by reference.

//Call by value function
void swap_by_value(int, int);
//Call by reference function
void swap_by_reference(int &, int&);

void swap_by_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Values in the function is:\n";
    cout << "\na = " << a << "; b = " << b;
}

void swap_by_reference(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Values in the function is:\n";
    cout << "\na = " << a << "; b = " << b << endl;
}

int main()
{
    int a=10, b=20;
    cout << "\nCalling by value:\n";

    cout << "Values in the main before swapping is:\n";
    cout << "\na = " << a << "; b = " << b << endl;

    swap_by_value(a, b);

    cout << "Values in the main after swapping is:\n";
    cout << "\na = " << a << "; b = " << b << endl;

    cout << "\nCalling by reference:\n";

    cout << "Values in the main before swapping is:\n";
    cout << "\na = " << a << "; b = " << b << endl;

    swap_by_reference(a, b);

    cout << "Values in the main after swapping is:\n";
    cout << "\na = " << a << "; b = " << b << endl;

    return 0;
}
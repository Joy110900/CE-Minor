#include <iostream>

using namespace std;

// function declaration
void swap(int &x, int &y);

int main ()
{
    // local variable declaration:
    int a = 100;
    int b = 200;
    cout << "\nCalling a function to swap the values using variable reference.\n";
    cout << "Before swap, value of a :" << a << endl;
    cout << "Before swap, value of b :" << b << endl;
    /* */
    swap_call_by_reference(a, b);
    cout << "After swap, value of a :" << a << endl;
    cout << "After swap, value of b :" << b << endl;
    return 0;
}

void swap_call_by_reference(int &x, int &y) {
    int temp;
    temp = x; /* save the value at address x */
    x = y; /* put y into x */
    y = temp; /* put x into y */
}

void swap_call_by_value(int x, int y) {
    int temp;
    temp = x; /* save the value at address x */
    x = y; /* put y into x */
    y = temp; /* put x into y */
}
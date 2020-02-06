/*
Write a CPP program to add corresponding elements of two 2D matrices using friend function.
Create two classes each capable of storing one 2D matrix.
Declare the matrix under private access specifier and access them outside the class.
*/
#include <iostream>

using namespace std;

class max1;
class max2;

class max1
{
    private:
    int arr2d[2][2];

    public:
    void get_value();
    friend void arr_add(max1, max2);
};

class max2
{
    private:
    int arr2d[2][2];

    public:
    void get_value();
    friend void arr_add(max1, max2);
};

int main()
{
    max1 a;
    max2 b;
    cout << "\nEnter values for first 2D array :\n";
    a.get_value();

    cout << "\nEnter values for second 2D array :\n";
    b.get_value();

    arr_add(a,b);

    return 0;
}

void max1:: get_value()
{   
    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 2; j++)
        {
            cin >> arr2d[i][j];
        }   
    }

    cout << "Input Matrix1 = " << endl;

    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 2; j++)
        {
            cout << arr2d[i][j] << "\t"; 
        }   
        cout << endl;
    }    
}

void max2:: get_value()
{   
    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 2; j++)
        {
            cin >> arr2d[i][j];
        }   
    }

    cout << "Input Matrix2 = " << endl;

    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 2; j++)
        {
            cout << arr2d[i][j] << "\t"; 
        }   
        cout << endl;
    }
}

void arr_add(max1 a, max2 b)
{
    int temp[2][2];
    cout << endl;
    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 2; j++)
        {
            cout << a.arr2d[i][j] + b.arr2d[i][j] << "\t";
        }   
        cout << endl;
    }    

}
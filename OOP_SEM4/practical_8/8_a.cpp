/*
WAP to sort out names stored in an array usingpointers. 
Allocate Memory Dynamically (usingnew operator).
*/
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter Total No. of Names: ";
    cin >> n;
    char* *str=new char*[n], *temp;
    cout << "\nEnter the names: \n";
    
    for(int i = 0; i <= n; i++)
    {
        str[i]=new char[10];
        cin.getline(str[i],10);
    }

    cout << "\nEntered Names: \n";
    for(int i = 0; i <= n; i++)
    {
        cout << str[i] << "  ";
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(strcmp(str[i],str[j])>0)
            {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
    cout << "\n\nSorted names: \n";
    for(int i = 0; i <= n; i++)
    {
        cout << str[i] << "  ";
    }
    cout << endl;
}
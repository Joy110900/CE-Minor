/*
Write a program which copies a user-specified textfile to another user-specified text file.  
Take sourcefile and destination file name from command-line arguments.
*/
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
    int i,sum=0;
    char str1[50],str2[50],temp[50];

    cout << "\nEnter source file name: " ;
    cin.getline(str1,50);
    fstream new_file;
    new_file.open(str1,ios::in);
    if(!new_file)
    {
        cout << "\nFile doesn't exist." << endl;
        new_file.close();
    }
    else
    {
        new_file.getline(temp,50);
        int len = strlen(temp);
        for(i=0;i<len;i++)
        {
            sum = sum + (temp[i]-48);
        }
        cout << "The sum of numbers in " << str1 << " is " << sum << endl;
        new_file.close();

        cout << "Enter file in which data has to be pasted: " ;
        cin.getline(str2,50);
        new_file.open(str2,ios::out);
        new_file << temp;
        new_file.close();
    }
}
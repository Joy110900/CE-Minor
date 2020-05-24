/*
WAP which reads a text from the keyboard and displays the following 
information on the screen in three columns:
a) Number of lines
b) Number of words
c) Number of characters 
Strings should be left justified and numbers should be right justified in a suitable width.
*/
#include <iostream>

using namespace std;

int main()
{
    string t;
    int w=1, c=0, l=1;
    
    cout << "Enter a text:\n";
    getline(cin, t);
    
    for(int i=0; t[i] != '\0'; i++)
    {
        if(t[i] == ' ')
        {
            w++;
        }

        if(t[i] == '\n')
        {
            l++;
        }

        c = t.length() - w - l;
    }
    cout << "\n---------------------------------------------------\n";
    cout << "Number of line\tNumber of words\tNumber of characters\n";
    cout << "\t" << l << "\t\t" << w << "\t\t" << c;
    cout << "\n---------------------------------------------------\n";
    return 0;
}
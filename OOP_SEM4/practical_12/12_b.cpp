/*
WAP to read in a text file and create another file that will accept every  
sequence of consecutive blank(more than one blank space) spaces is
replaced by single space. 
*/
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream file1;
    ofstream file2;
    string sfile,tfile;
    
    cout<<"\nEnter Source File Name-";
    cin>>sfile;
    cout<<"\nEnter Target File Name-";
    cin>>tfile;
    
    file2.open(sfile);
    file2 << "\nMy Name  is Joy. I am  a  student of Nirma  University." << endl;
    file2.close();
    
    file1.open(sfile);
    file2.open(tfile);

    char varch,p=file1.get();
    
    while(!file1.eof())
    {
        file2.put(p);
        varch=file1.get();

        if(p==' ' && varch==' ')
        {  
            p=varch;
            varch=file1.get();
        }
        p=varch;
   
   }

   file1.close();
   file2.close();
   cout << "\nTarget File Contents:\n";
   file1.open(tfile);
   
   while(!file1.eof())
   {
        file1.get(varch);
        cout<<varch;
   }

   file1.close();
    
    return 0;
 }
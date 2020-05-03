#include <iostream>

using namespace std;

int main()
{
    int a, b, total_elems;
    int t1 = 1, t2 = 1, in1[a], in2[b];

// Input 1st array elements
    cout << "Enter first array size: ";
    cin >> a;
    cout << "\nEnter values for first array\n";

    for(int i=0; i < a; i++)                        
    {
        cin >> in1[i];
    }

// Input 2nd array elements
    cout << "Enter second array size: ";
    cin >> b;
    cout << "\nEnter values for second array\n";

    for(int i=0; i < b; i++)                        
    {
        cin >> in2[i];
    }

// Initialise an array with size=total elements of both input arrays
total_elems = a + b;
int big[total_elems];



// Count unique elems for 1st arr
    for(int i=0; i < a; i++)                        
    {
        for(int j=i+1; j < a; j++)
        {
            if(in1[i] == in1[j])
                break;

            if(j == a-1)
                t1++;
        }
    }

// Count unique elems for 2nd arr
    for(int i=0; i < b; i++)                        
    {
        for(int j=i+1; j < b; j++)
        {
            if(in2[i] == in2[j])
                break;

            if(j == b-1)
                t2++;
        }
    }

    int u1[t1], u2[t2], j1 = 0, k1 = 0;         //initialize unique arr

    for(int i=0; i < a; i++)                    //make 1st unique array
    {
        for(int j=i+1; j < a; j++)
        {
            if(in1[i] == in1[j])
                break;

            if(j == a-1)
            {
                u1[j1] = in1[i];
                j1++;
            }
        }
    }

    u1[t1-1] = in1[a-1];                        //append last elem

    for(int i=0; i < b; i++)                        //make 2nd arr unique
    {
        for(int j=i+1; j < b; j++)
        {
            if(in2[i] == in2[j])
                break;

            if(j == b-1)
            {
                u2[k1] = in2[i];
                k1++;
            }
        }
    }

    u2[t2-1] = in2[b-1];                            //append last elem

    int temp = 0;

    for(int i=0; i < a; i++)                        //count unique elems for 1st arr
    {
        for(int j=0; j < b; j++)
        {
            if(u1[i] == u2[j])
                temp++;
        }
    }

    int intersection[temp], interlen;
    interlen = temp;

    for(int i=0; i < a; i++)                        //count unique elems for 1st arr
    {
        for(int j=i+1; j < b; j++)
        {
            if(u1[i] == u2[j])
            {
                intersection[temp - 1] = u1[i];
                temp--;
            }
        }
    }

    cout << endl;

    for(int i=0; i < interlen; i++)
    {
        cout << endl << intersection[i] << "   ";
    }

    for(int i=0; i < t2; i++)
    {
        cout << u2[i] << "   ";
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a = 4, b = 4;
    int t1 = 1, t2 = 1, in1[a], in2[b];

    cout << "Enter 4 values for first array" << endl << endl;

    for(int i=0; i < a; i++)                        //input 1st array elems
    {
        cin >> in1[i];
    }

    cout << "Enter 4 values for second array" << endl << endl;

    for(int i=0; i < b; i++)                        //input 2nd array elems
    {
        cin >> in2[i];
    }

    for(int i=0; i < a; i++)                        //count unique elems for 1st arr
    {
        for(int j=i+1; j < a; j++)
        {
            if(in1[i] == in1[j])
                break;

            if(j == a-1)
                t1++;
        }
    }

    for(int i=0; i < b; i++)                        //count unique elems for 2nd arr
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

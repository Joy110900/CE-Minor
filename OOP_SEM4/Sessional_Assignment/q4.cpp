/*
Declare a template class called numbertest having an array of generic type as a
data member, named numbers[15].
Define following generic(template) member functions:
- sort to arrange elements in ascending order
- sort to arrange elements in descending order
- find_max to find and return maximum from the array
- find_avg to find and average of the array
Define main to illustrate usage of these functions to process two different types
of data.
*/
#include <iostream>

using namespace std;

int size = 3;

template<class T>

class numbertest
{
    public:
    T numbers[2];

    void set_arr()
    {
        cout << "\nEnter elements of your array:\n";
        for(int i=0; i<size; i++)
        {
            cin >> numbers[i];
        }

        cout << "\nEntered array is:\n";

        for(int i=0; i<size; i++)
        {
            cout << numbers[i] << " ";
        }
    }

    void sort_asc()
    {
        for(int i=0; i<size; i++)
        {
            for(int j=i; j<size; j++)
            {
                if(numbers[j] < numbers[i])
                {
                    T t;
                    t = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = t;
                }
            }
        }

        cout << "\nAscending Sorted Array is:\n";

        for(int i=0; i<size; i++)
        {
            cout << numbers[i] << " ";
        }
    } 

    void sort_dsc()
    {
        for(int i=0; i<size; i++)
        {
            for(int j=i; j<size; j++)
            {
                if(numbers[j] > numbers[i])
                {
                    T t;
                    t = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = t;
                }
            }
        }

        cout << "\nDescending Sorted Array is:\n";

        for(int i=0; i<size; i++)
        {
            cout << numbers[i] << " ";
        }
    }

    T max_arr()
    {
        T maxt;
        maxt = numbers[0];

        for(int i=1; i<size; i++)
        {
            if(numbers[i] > maxt)
            {
                maxt = numbers[i];
            }
        }

        cout << "\nMax element of the array = " << maxt << endl;

        return maxt;
    }

    float avg_arr()
    {
        float avgt;
        avgt = numbers[0];

        for(int i=1; i<size; i++)
        {
            avgt += numbers[i];
        }

        avgt /= float(size);

        cout << "\nAverage of the array = " << avgt << endl;

        return avgt;
    }
};


int main()
{
    cout << "Processing integers elements\n";
    numbertest<int> test;
    test.set_arr();
    test.sort_asc();
    test.sort_dsc();
    test.max_arr();
    test.avg_arr();

    cout << "Processing float elements\n";
    numbertest<float> testf;
    testf.set_arr();
    testf.sort_asc();
    testf.sort_dsc();
    testf.max_arr();
    testf.avg_arr();

    return 0;
}
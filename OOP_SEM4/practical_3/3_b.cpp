/*
 Create a class Distance, which accepts data in feet and inches, adds two distances and displays the result in the appropriate form.
*/

#include <iostream>

using namespace std;

class dist
{
    int feet, inch;
    
    public:
    void enter_dist();
    void add_dist(dist, dist);
};

int main()
{
    dist a, b;
    a.enter_dist();
    b.enter_dist();
    a.add_dist(a, b);
}

void dist:: enter_dist()
{
    cout << "\nEnter total feet: ";
    cin >> feet;

    cout << "\nEnter total inch: ";
    cin >> inch;
    
    while(inch >= 12)
    {
        cout << "\nPlease enter proper value of inch\nEnter total inch";
        cin >> inch;
    }
}
void dist:: add_dist(dist a, dist b)
{
    int f, i;
    i = a.inch + b.inch;
    f = a.feet + b.feet;
    if(i >= 12)
    {
        i -= 12;
        f += 1;
    }
    
    cout << "\nSum of distances = " << f << "feet " << i << " inches"; 
}
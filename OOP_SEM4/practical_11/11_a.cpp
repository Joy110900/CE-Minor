/*
Declare a class Window having data member as integer x ,y,
top and bottom and Title of window and member function as set Window to set 
window coordinates and setTitle() to display Title and Draw to draw window. 
Create 5 window of different size using pointers.
*/
#include <iostream>

using namespace std;

class window
{
    public:
    int x, y, top, bottom;
    string title;

    window()
    {
        x = 0;
        y = 0;
        top = 0;
        bottom = 0;
        title = "NA";
    }

    void setwin()
    {
        cout << "Enter value of x, y, Top and Bottom coordinates:\n";
        cin >> x;
        cin >> y;
        cin >> top;
        cin >> bottom;
        cout << "\nx = " << x << ", y = " << y << ", Top = " << top << ", Bottom = " << bottom << endl;
    }

    void set_title()
    {
        cout << "Enter title of your window:\n";
        getline(cin, title);
    }

    void draw()
    {
        cout << "\n---------------------------------------------------------------------\n";        
        cout << "\nA window titled " << title << " with coordinates " << x << ", " << y << ", " << top << ", " << bottom << " is created.\n";
        cout << "\n---------------------------------------------------------------------\n";
    }
};

int main()
{
    window w1, w2, w3, w4, w5;
    window *wptr;

    wptr = &w1;
    wptr -> set_title();
    wptr -> setwin();
    wptr -> draw();
    
    wptr = &w2;
    wptr -> set_title();
    wptr -> setwin();
    wptr -> draw();

    wptr = &w3;
    wptr -> set_title();
    wptr -> setwin();
    wptr -> draw();

    wptr = &w4;
    wptr -> set_title();
    wptr -> setwin();
    wptr -> draw();

    wptr = &w5;
    wptr -> set_title();
    wptr -> setwin();
    wptr -> draw();    
    
    return 0;
}
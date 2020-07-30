#include <iostream>
using namespace std;

class rectangle;

class figure
{
    public:
    virtual void pf()
    {
        cout << "\nThis is the base class.\n";
    }
};

class rectangle: public figure
{
    public:
    void pf()
    {
        cout << "\nThis is derived class\n";
    }
};

int main()
{
    figure* f;
    rectangle r;

    f=&r;
    f -> pf();

    return 0;
}

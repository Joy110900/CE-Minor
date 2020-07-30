#include <iostream>
#include <cstring>

using namespace std;

class test
{    
    private:
    int m_int; // Member variable.
    
    public:
    static test** CreateArray(unsigned int count) 
    {
        test** res = NULL;
        if(count)
        {
        // Calculate size of allocation.
            unsigned long size = count * sizeof(test*);
        // Allocate memory and zero.
            if(res = (test**) malloc(size))
                memset(res, 0x00, size);
        }
        return( res );
    }
};

int main()
{
    int i = 0;

    test** p2pArray;

    // Init a dynamic array of objects
    test Array[10];

    if(p2pArray = test::CreateArray(10))
    {
        for( i=0; i<10; ++i)
            p2pArray[i] = &Array[i]; 
        
        // Finished with dynamic array 
        delete(p2pArray);
        p2pArray = NULL;
    }

    // Init a new dynamic array
    if(p2pArray = test::CreateArray(5))
    {
        // Init new objects 
        for( i=0; i<5; ++i )
            p2pArray[i] = new test();
        
        //Destroy every object
        for( int i=0; i<5; ++i )
        {
            delete( p2pArray[i] );
            p2pArray[i] = NULL;
        }
        // Finished with dynamic array.
        delete( p2pArray );
        p2pArray = NULL;
    }
    return( 0 );
}
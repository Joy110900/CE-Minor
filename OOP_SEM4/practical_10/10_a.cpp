/*
Define template class for add, update and traverse operations to implement Queue datastructure. 
Demonstrate the operations on Queue using integer and double types.
*/
#include <iostream>

using namespace std;

// Class for queue
template <class X>
class queue 
{
	X *arr; 		// array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;  	// front points to front element in the queue (if any)
	int rear;   	// rear points to last element in the queue
	int count;  	// current size of the queue

public:
	queue(int size=10);		// constructor
	void dequeue();
	void add(X x);
	int size();
    void print();
};

// Constructor to initialize queue
template <class X>
queue<X>::queue(int size)
{
	arr = new X[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Utility function to add an item to the queue
template <class X>
void queue<X>::add(X item)
{
	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to remove front element from the queue
template <class X>
void queue<X>::dequeue()
{
	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

// Utility function to return the size of the queue
template <class X>
int queue<X>::size()
{
	return count;
}

// Utility function to print queue
template <class X>
void queue<X>::print()
{
    cout << "Queue - ";
	for (int i=0; i<count; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

// main function
int main()
{
	// create a queue of capacity 4
	queue<int> i(4);
    queue<double> d(4);

	i.add(1);
	i.add(2);
	i.add(3);
	i.add(6);
	cout << "Queue size is " << i.size() << endl;
    i.print();

	i.dequeue();
	i.dequeue();
	i.dequeue();

    cout << "Queue size is " << i.size() << endl;
    i.print();

    d.add(3.2);
	d.add(3.14);
	d.add(3.432432);
	d.add(6.2342);
	cout << "Queue size is " << d.size() << endl;
    d.print();

	d.dequeue();
	d.dequeue();
	d.dequeue();

    cout << "Queue size is " << d.size() << endl;
    d.print();

	return 0;
}
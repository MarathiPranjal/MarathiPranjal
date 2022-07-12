#include <iostream>
using namespace std;

class stack
{
    int top;
    int *arr;
    int size;

public:
    // creating constructor
    stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }

    // creating functions that will perform some operations on stack

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!!!\n";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!!!\n";
        }
        else
        {
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << arr[top] << endl;
        }
    }

    void isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Stack is not empty.\n";
        }
    }

    void isFull()
    {
        if (top == size - 1)
        {
            cout << "Stack is full.\n";
        }
        else
        {
            cout << "Stack is not full.\n";
        }
    }
};

int main()
{
    // initialization of stack with array size of 5
    stack s(5);

    // calling its operations

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.pop();
    s.peek();

    s.pop();
    s.peek();

    s.isEmpty();
    s.isFull();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

#define CAP 5

class my_queue
{
private:
    int val[CAP];
    int front = 0;
    int rear = 0;

public:
    void push(int x);
    void display();
    int pop();
    bool isEmpty();
    int frontVal();
};

void my_queue::push(int x)
{
    if (rear == CAP - 1)
    {
        cout << "Overflow" << endl;
    }

    val[rear] = x;
    rear++;
}

int my_queue::pop()
{
    if (front == 0 && rear == 0)
    {
        cout << "Underflow..." << endl;
        return -1;
    }

    int temp = val[front];
    front++;

    if (front >= rear)
    {
        front = 0;
        rear = 0;
    }

    return temp;
}

void my_queue::display()
{
    if (front > rear)
    {
        cout << "Underflow..." << endl;
        return;
    }

    for (int i = front; i < rear; i++)
        cout << val[i] << "  ";
    cout << endl;
}

bool my_queue::isEmpty()
{
    if (front > rear || (front == 0 && rear == 0))
    {
        return false;
    }

    return true;
}

int my_queue::frontVal()
{
    if (front == 0 && rear == 0)
        return -1;

    cout << front << " : " << rear << endl;
    return val[front];
}

int main()
{
    IOS;

    my_queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    // cout << q.pop() << endl;

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    // cout << "Front: " << q.frontVal() << endl;
    // cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << "Empty: " << q.pop() << endl;

    return 0;
}
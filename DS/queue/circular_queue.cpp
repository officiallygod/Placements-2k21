#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

#define C 10

class cir_queue
{
private:
    int arr[C];
    int front = -1;
    int rear = -1;

public:
    void push(int x);
    int pop();
    void display();
};

void cir_queue::push(int x)
{
    if ((front == 0 && rear == C - 1) || (rear == front - 1))
    {
        cout << "Overflow..." << endl;
        return;
    }
    else if (front == -1 and rear == -1)
    {
        front = rear = 0;
        arr[rear] = x;
    }
    else if (rear == C - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}

int cir_queue::pop()
{
    if (front == -1)
    {
        cout << "Underflow..." << endl;
        return -1;
    }

    int temp = arr[front];
    arr[front] = -1;
    if (front == rear)
        front = rear = -1;
    else if (front == C - 1)
        front = 0;
    else
        front++;

    return temp;
}

void cir_queue::display()
{
    if (front == -1)
    {
        cout << "Underflow..." << endl;
        return;
    }

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
    else
    {
        for (int i = front; i < C; i++)
            cout << arr[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    IOS;

    cir_queue cq;

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);

    cq.display();

    cq.pop();
    cq.pop();
    cq.pop();

    cq.push(60);
    cq.push(70);
    cq.push(80);

    cq.display();

    return 0;
}
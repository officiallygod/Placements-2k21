#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

#define CAP 20

class my_stack
{
private:
    int val[CAP];
    int top = 0;

public:
    void push(int x);
    void display();
    int pop();
    bool isEmpty();
    int topVal();
};

void my_stack::push(int x)
{
    if (top == CAP - 1)
    {
        cout << "Overflow..." << endl;
        return;
    }

    val[top] = x;
    top++;
}

int my_stack::pop()
{
    if (top <= 0)
    {
        cout << "Underflow..." << endl;
        return -1;
    }

    top--;
    int temp = val[top];
    return temp;
}

void my_stack::display()
{
    if (top <= 0)
    {
        cout << "Underflow..." << endl;
        return;
    }

    for (int i = 0; i < top; i++)
    {
        cout << val[i] << "  ";
    }

    cout << endl;
}

bool my_stack::isEmpty()
{
    if (top <= 0)
        return false;
    return true;
}

int my_stack::topVal()
{
    if (top <= 0)
        return -1;

    return val[top];
}

int main()
{
    IOS;

    my_stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << st.pop() << endl;
    cout << st.pop() << endl;

    cout << st.isEmpty() << endl;
    cout << st.topVal() << endl;

    return 0;
}
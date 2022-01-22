#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

class Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
    }

    Node(int x)
    {
        data = x;
        next = NULL;
    }

    Node *insertFront(Node *head, int x);
    Node *insertRear(Node *head, int x);
    Node *popFront(Node *head);
    Node *popRear(Node *head);
    void display(Node *head);
};

Node *Node::insertFront(Node *head, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
        return temp;

    temp->next = head;
    return temp;
}

Node *Node::insertRear(Node *head, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
        return temp;

    if (head->next == NULL)
    {
        head->next = temp;
        return head;
    }

    Node *curr = head;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}

Node *Node::popFront(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *Node::popRear(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *curr = head;

    while (curr->next->next != NULL)
        curr = curr->next;

    Node *temp = curr->next;
    curr->next = NULL;
    free(temp);
    return head;
}

void Node::display(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << "  ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    IOS;
    Node node;
    Node *head = NULL;

    head = node.insertFront(head, 10);
    head = node.insertFront(head, 20);
    head = node.insertFront(head, 30);
    head = node.insertRear(head, 40);
    head = node.insertRear(head, 50);
    node.display(head);
    head = node.popFront(head);
    head = node.popRear(head);
    node.display(head);
    head = node.insertFront(head, 30);
    head = node.insertRear(head, 50);
    node.display(head);

    return 0;
}
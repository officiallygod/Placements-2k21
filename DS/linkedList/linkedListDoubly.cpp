#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
    }

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
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

    temp->right = head;
    head->left = temp;
    return temp;
}

Node *Node::insertRear(Node *head, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
        return temp;

    if (head->right == NULL)
    {
        head->right = temp;
        temp->left = head;
        return head;
    }

    Node *curr = head;

    while (curr->right != NULL)
        curr = curr->right;

    curr->right = temp;
    temp->left = curr;
    return head;
}

Node *Node::popFront(Node *head)
{
    if (head == NULL || head->right == NULL)
        return NULL;

    Node *temp = head;
    head = head->right;
    head->left = NULL;
    free(temp);
    return head;
}

Node *Node::popRear(Node *head)
{
    if (head == NULL || head->right == NULL)
        return NULL;

    Node *curr = head;

    while (curr->right->right != NULL)
        curr = curr->right;

    Node *temp = curr->right;
    curr->right = NULL;
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
        curr = curr->right;
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
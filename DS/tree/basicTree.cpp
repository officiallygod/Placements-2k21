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
    Node() {}
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }

    Node *insertChild(Node *root, int x);
    void displayPreorder(Node *root);
    void displayInorder(Node *root);
    void displayPostorder(Node *root);
};

Node *Node::insertChild(Node *root, int x)
{
    Node *temp = new Node(x);

    if (root == NULL)
        return temp;

    Node *curr = root;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (x > curr->data)
        {
            prev = curr;
            curr = curr->right;
        }
        else
        {
            prev = curr;
            curr = curr->left;
        }
    }

    if (x > prev->data)
        prev->right = temp;
    else
        prev->left = temp;

    return root;
}

void Node::displayPreorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "  ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}

void Node::displayInorder(Node *root)
{
    if (root == NULL)
        return;

    displayInorder(root->left);
    cout << root->data << "  ";
    displayInorder(root->right);
}

void Node::displayPostorder(Node *root)
{
    if (root == NULL)
        return;

    displayPostorder(root->left);
    displayPostorder(root->right);
    cout << root->data << "  ";
}

int main()
{
    IOS;

    Node node;
    Node *root = NULL;

    root = node.insertChild(root, 50);
    root = node.insertChild(root, 40);
    root = node.insertChild(root, 70);
    root = node.insertChild(root, 60);
    root = node.insertChild(root, 80);
    cout << "Traversals..." << endl;
    cout << "Preorder: ";
    node.displayPreorder(root);
    cout << endl
         << endl
         << "Inorder: ";
    node.displayInorder(root);
    cout << endl
         << endl
         << "Postorder: ";
    node.displayPostorder(root);
    cout << endl;

    return 0;
}
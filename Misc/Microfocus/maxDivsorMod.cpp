#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int key;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void createFactorTree(struct Node **node_ref, int v)
{
    (*node_ref) = newNode(v);
    for (int i = 2; i <= v / 2; i++)
    {
        if (v % i != 0)
            continue;
        createFactorTree(&((*node_ref)->left), i);
        createFactorTree(&((*node_ref)->right), v / i);
        return;
    }
}

int maxDepth(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main()
{
    int val = 64;
    struct Node *root = NULL;
    createFactorTree(&root, val);
    cout << maxDepth(root) - 1 << endl;
    return 0;
}

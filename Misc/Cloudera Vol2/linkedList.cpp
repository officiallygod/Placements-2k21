#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    // Default constructor
    SinglyLinkedListNode()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    SinglyLinkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Utility function to create a new Node
SinglyLinkedListNode *newNode(int data)
{
    SinglyLinkedListNode *temp = new SinglyLinkedListNode();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

SinglyLinkedListNode *condense(SinglyLinkedListNode *head)
{
    unordered_set<int> seen;
    SinglyLinkedListNode *start = head;
    SinglyLinkedListNode *curr = head;
    SinglyLinkedListNode *prev = NULL;
    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }

    return start;
}

/* Function to print nodes in a given linked list */
void printList(SinglyLinkedListNode *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    SinglyLinkedListNode *start = new SinglyLinkedListNode(3);
    start->next = new SinglyLinkedListNode(4);
    start->next->next = new SinglyLinkedListNode(3);
    start->next->next->next = new SinglyLinkedListNode(2);
    start->next->next->next->next = new SinglyLinkedListNode(6);
    start->next->next->next->next->next = new SinglyLinkedListNode(1);
    start->next->next->next->next->next->next = new SinglyLinkedListNode(2);

    printf("Linked list before removing duplicates : \n");
    printList(start);

    SinglyLinkedListNode *head = condense(start);

    printf("\nLinked list after removing duplicates : \n");
    printList(head);

    return 0;
}
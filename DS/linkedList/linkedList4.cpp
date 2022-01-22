#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
// with given data
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to insert a node at the
// beginning of the Linked List
void push(struct Node **head_ref, int new_data)
{
    // allocate node
    struct Node *new_node = newNode(new_data);

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        if (node->next)
            cout << "->";
        node = node->next;
    }
    cout << "\n";
}

Node *multiply_node(Node *head)
{

    Node *mul = NULL;
    Node *prev = NULL;
    int new_val = 0, carry = 0;
    head = reverse(head);
    Node *cur = head;
    // printList(head);
    //6->4->9
    while (cur != NULL)
    {
        new_val = cur->data;
        new_val = new_val * 4;
        new_val = new_val + carry;
        carry = new_val / 10;
        new_val = new_val % 10;
        cur->data = new_val;

        prev = cur;
        cur = cur->next;

        // Node *new_node = newNode(new_val);
        // new_node->next = mul;
        // mul = new_node;
    }

    while (carry != 0)
    {
        new_val = carry % 10;
        carry = carry / 10;
        Node *temp = newNode(new_val);
        prev->next = temp;
        prev = prev->next;
    }
    head = reverse(head);
    return head;
}

int main()
{
    struct Node *first = NULL;
    struct Node *second = NULL;

    // create first list 9->4->6
    // 3784
    push(&first, 6);
    push(&first, 5);
    push(&first, 7);
    push(&first, 8);
    push(&first, 9);

    printList(first);
    first = multiply_node(first);
    printList(first);

    return 0;
}
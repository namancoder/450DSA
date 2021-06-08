// CPP program to reverse a linked list
// in groups of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node *rotate(Node **head, int k)
{
    if (k == 0)
        return *head;
    Node *current = *head;
    int count = 1;

    while (count < k && current)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return *head;
    Node *kthNode = current;
    Node *newHead = current->next;
    while (current->next)
    {
        current = current->next;
    }
    kthNode->next = NULL;
    current->next = *head;

    return newHead;
}

/* Driver code*/
int main()
{
    Node *head = NULL;

    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list \n";
    printList(head);
    head = rotate(&head, 3);

    cout << "\nReversed Linked list \n";
    printList(head);

    return (0);
}

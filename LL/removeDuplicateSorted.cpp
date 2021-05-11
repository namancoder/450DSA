/* C++ Program to remove duplicates from a sorted linked list */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

void removeDuplicates(Node *head)
{
    Node *current = head;
    Node *next_next;

    if (!current)
        return;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
            current = current->next;
    }
}

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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

int main()
{

    Node *head = NULL;

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    cout << "Linked list before duplicate removal ";
    printList(head);

    /* Remove duplicates from linked list */
    removeDuplicates(head);

    cout << "\nLinked list after duplicate removal ";
    printList(head);

    return 0;
}

// This code is contributed by rathbhupendra

/* CPP Program to move last element
to front in a given linked list */
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node
{
public:
    int data;
    Node *next;
};

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

void moveToFront(Node **head_ref)
{
    if (!*head_ref || !((*head_ref)->next))
        return;

    Node *secLast = NULL;
    Node *last = *head_ref;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;
    last->next = *head_ref;

    *head_ref = last;
}
/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Driver code */
int main()
{
    Node *start = NULL;

    /* The constructed linked list is:
	1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before moving last to front\n";
    printList(start);

    moveToFront(&start);

    cout << "\nLinked list after removing last to front\n";
    printList(start);

    return 0;
}


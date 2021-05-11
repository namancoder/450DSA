/* C++ Program to remove duplicates in an unsorted
linked list */
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};

// Utility function to create a new Node
struct Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void removeDuplicates(struct Node *start)
{

    struct Node *ptr1, *ptr2, *dup;

    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void removeDuplicateHashing(struct Node *start)
{
    unordered_set<int> seen;

    struct Node *curr = start;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())//if element is found again
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr=prev->next;
    }
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
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
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next =
        newNode(11);
    start->next->next->next->next->next->next =
        newNode(10);

    printf("Linked list before removing duplicates ");
    printList(start);

    removeDuplicateHashing(start);

    printf("\nLinked list after removing duplicates ");
    printList(start);

    return 0;
}

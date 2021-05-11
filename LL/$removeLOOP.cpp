#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

// void removeLoop(Node *loop_node, Node *head)
// {
//     Node *ptr1;
//     Node *ptr2;

//     ptr1 = head;
//     while (1)
//     {
//         ptr2 = loop_node;
//         while (ptr2->next != loop_node && ptr2->next !ptr1)
//             ptr2 = ptr2->next;

//         if (ptr2->next == ptr1)
//             break;

//         ptr1 = ptr1->next;
//     }
// }

void removeLoop(Node *loop_node, Node *head)
{
    Node *ptr1 = loop_node;
    Node *ptr2 = loop_node;

    int k = 1;
    //count the number of nodes in loop
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }

    ptr1 = head;
    ptr2 = head;

    for (int i = 0; i < k; i++) //k nodes after head;
    {
        ptr2 = ptr2->next;
    }
    while (ptr2 != ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    ptr2->next = NULL;
}
bool hasLoop(Node *first)
{
    Node *slow = first;
    Node *fast = first;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            removeLoop(slow, first);
            return true;
        }
    }
    return false;
}

void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = new Node;

    /* put in the data  */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
push(&head, 50);
    push(&head, 20);
    //push(&head, 4);
    push(&head, 15);
    push(&head, 4);
    push(&head, 10);

    /// Create a loop for testing

    //head->next->next->next->next = head;
        head->next->next->next->next->next = head->next->next;

    printList(head);

    cout << endl;
    if (hasLoop(head))
    {
        cout << "Loop found";
        printList(head);
    }
    else
        cout << "No Loop";

    return 0;
}

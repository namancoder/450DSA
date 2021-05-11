// C++ program to add 1 to a linked list
#include <bits/stdc++.h>
using namespace std;

/* Linked list node */
class Node
{
public:
    int data;
    Node *next;
};

/* Function to create a new node with given data */
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *addOneUtil(Node *head)
{
    Node *res = head;
    Node *temp, *prev = NULL;

    int carry = 1, sum;

    while(head)
    {

        sum = carry+head->data;

        carry = (sum>=10)?1:0;
        sum%=10;
        head->data = sum;

        temp = head;
        head = head->next;
    }

    if(carry)
    temp->next = newNode(carry);

    return res;
}
Node *addOne(Node *head)
{
    head = reverse(head);
    head = addOneUtil(head);
    return reverse(head);
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << endl;
}

/* Driver program to test above function */
int main()
{
    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);

    cout << "List is ";
    printList(head);

    head = addOne(head);

    cout << "\nResultant list is ";
    printList(head);

    return 0;
}

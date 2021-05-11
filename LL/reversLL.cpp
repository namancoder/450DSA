#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    Node *reverseRecur(Node *node)
    {
        // if (node == NULL)
        //     return NULL;
        if (node->next == NULL)
        {
            head = node;
            return node;
        }
        Node *node1 = reverseRecur(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }

    Node* reverseSize(Node *head, int k)
    {
        if (!head)
            return NULL;

        Node *current = head;
        Node *next = NULL;
        Node *prev = NULL;

        int count = 0;

        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if(next !=NULL)
        head->next = reverse(next,k);
        return prev;

    }

    bool detectLoop(struct Node* h)
    {

    }
    // Function to print linked list
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{

    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    //ll.reverse();
    //ll.reverseRecur(ll.head);
    //head = reverseSize(head, 3);

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}

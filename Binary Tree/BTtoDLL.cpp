//#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    node *left;
    node *right;
};
BinaryTree2DoubleLinkedList(Node *root, Node **head)
{
    if (!root)
        return;

    static Node *prev = NULL;
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    BinaryTree2DoubleLinkedList(root->left, head);

    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BinaryTree2DoubleLinkedList(root->right, head);
}
int main()
{

    /*create root*/
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    Node *head = NULL;

    return 0;
}

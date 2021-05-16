#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

void mirror(Node *node)
{
    if (!node)
        return;
    else
    {
        Node *temp;

        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void inOrder(Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
int main()
{

    /*create root*/
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);
    inOrder(root);
    //printLevelOrder(root);

    return 0;
}
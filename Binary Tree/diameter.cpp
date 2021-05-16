#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

void printLevelOrder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *topp = q.front();
        cout << topp->data << " ";
        q.pop();

        if (topp->left)
            q.push(topp->left);
        if (topp->right)
            q.push(topp->right);
    }
}

int height(Node *node)
{

    if (!node)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}
int diamter(Node *tree)
{
    if (!tree)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diamter(tree->left);
    int rdiameter = diamter(tree->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
int main()
{

    /*create root*/
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout << diamter(root) << endl;
    cout << height(root) << endl;

    //printLevelOrder(root);
    

    return 0;
}
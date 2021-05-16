#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

void inOrder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void postOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);

    stack<int> out;
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        out.push(curr->data);

        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}

void preOrder(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        cout << curr->data << " ";
        s.pop();
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
    return;
}
int main()
{

    /*create root*/
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    preOrder(root);
    //printLevelOrder(root);

    return 0;
}
#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;
int toSumTree(Node *root)
{
    if (!root)
        return 0;
    int old_val = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);

    return root->data + old_val;
}
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
int main()
{

    /*create root*/

    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    int x = toSumTree(root);

    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout << "Inorder Traversal of the resultant tree is: \n";
    inOrder(root);

    return 0;
}
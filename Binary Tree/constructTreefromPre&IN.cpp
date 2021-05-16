#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

int searchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            return i;
        }
    }
    return -1;
}
Node *generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return NULL;
    }

    Node *node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->left = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
    node->right = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
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
    int inorder[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7};
    int preorder[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};
    int len = sizeof(inorder) / sizeof(int);
    //printLevelOrder(root);
    Node *T = generateFromTraversal(inorder, preorder, 0, len - 1);
    preOrder(T);

    return 0;
}
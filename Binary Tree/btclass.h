#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    // val is the key or the value that
    // has to be added to the data part

    Node(int val)
    {
        data = val;

        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
    int height(Node *node)
    {
        // base case tree is empty
        if (node == NULL)
            return 0;

        // If tree is not empty then height = 1 + max of left
        // height and right heights
        return 1 + max(height(node->left), height(node->right));
    }
};
#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(Node *root, int *height)
{
    int lh, rh = 0;

    int l = 0, r = 0; //checks if left or right subtree is balanced or not
    if (root == NULL)
    {
        *height = 0;
        return 1;
    }
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right, &rh);

    *height = (lh > rh ? lh : rh) + 1;
    if (abs(lh - rh) >= 2)
        return 0;

    else
        return 1;
}

int height(Node *node)
{

    if (!node)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}
bool isBalanced1(Node *root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced1(root->left) && isBalanced1(root->right))
        return 1;

    /* If we reach here then
    tree is not height-balanced */
    return 0;
}
int main()
{

    /*create root*/
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height = 0;

    if (isBalanced(root, &height))
        cout << "Maje aa gaye";
    else
        cout << "Nahi aaye Maje😭";

    // if (isBalanced1(root))
    //     cout << "Maje aa gaye";
    // else
    //     cout << "Nahi aaye Maje😭";

    return 0;
}
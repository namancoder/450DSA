#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left, *right;
};

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}

int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}

void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(2);
    root->left->right = newNode(9);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}
#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

void zigZagTraversal(Node *root)
{
    if (!root)
        return;
    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    currentLevel.push(root);
    bool leftToRight = true;
    while (!currentLevel.empty())
    {
        Node *temp = currentLevel.top();
        currentLevel.pop();

        
            cout << temp->data << " ";
            if (leftToRight)
            {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
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
    // cout << diamter(root) << endl;
    // cout << height(root) << endl;

    //printLevelOrder(root);

    zigZagTraversal(root);

    return 0;
}
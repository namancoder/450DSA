#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

void diagonalPrintUtil(Node *root, int d, map<int, vector<int>> &diagonalPrint)
{
    if (!root)
        return;
    diagonalPrint[d].push_back(root->data);

    diagonalPrintUtil(root->left, d + 1, diagonalPrint);
    diagonalPrintUtil(root->right, d, diagonalPrint);
}
void diagonalPrint(Node *root)
{
    map<int, vector<int>> diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);

    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it : diagonalPrint)
    {
        vector<int> v = it.second;
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
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
    // cout << diamter(root) << endl;
    // cout << height(root) << endl;

    //printLevelOrder(root);

    diagonalPrint(root);

    return 0;
}

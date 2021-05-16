#include "btclass.h"
#include <bits/stdc++.h>
using namespace std;

void printLeftView(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 1)
                cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void rightViewUtil(Node *root, int level, int *max_level)
{
    if (!root)
        return;

    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }

    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
void rightView(Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

void fillMap(Node *root, int d, int l,
             map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;

    if (m.count(d) == 0)
    {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l)
    {
        m[d] = make_pair(root->data, l);
    }

    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}

void topView(Node *root)
{
    map<int, pair<int, int>> m;
    fillMap(root, 0, 0, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second.first << " ";
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
    leftView(root);
    //printLevelOrder(root);

    return 0;
}
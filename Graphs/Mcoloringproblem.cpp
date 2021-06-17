#include <bits/stdc++.h>
using namespace std;

#define V 4

bool isSafe(int node, int color[], bool graph[V][V], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && (((color[k] == col))))
            return false;
    }
    return true;  
}

bool solve(int node, int color[], int m, int N, bool graph[V][V])
{
    if (node == N)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int main()
{
    //int V = 4;
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 2;
    int color[V] = {0};

    if (solve(0, color, m, V, graph))
        cout << "Yes";
    else
        cout << "NO";

    return 0;
}
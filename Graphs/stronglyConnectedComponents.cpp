#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<int> graph[], int i, vector<int> &stack, bool visited[])
{
    visited[i] = true;
    for (auto nbr : graph[i])
    {
        if (!visited[nbr])
            dfs1(graph, nbr, stack, visited);
    }
    stack.push_back(i);
}

void dfs2(vector<int> graph[], int node, bool visited[])
{
    visited[node] = true;
    cout << node << " ";
    for (auto x : graph[node])
    {
        if (!visited[x])
            dfs2(graph, x, visited);
    }
}
void solve(vector<int> graph[], vector<int> rev_graph[], int N)
{
    bool visited[N];
    memset(visited, 0, N);
    vector<int> stack;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs1(graph, i, stack, visited);
        }
    }
    memset(visited, 0, N);

    for (int x = stack.size() - 1; x >= 0; x--)
    {
        int node = stack[x];
        if (!visited[node])
            dfs2(rev_graph, node, visited);
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> graph[N];
    vector<int> rev_graph[N];

    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }

    solve(graph, rev_graph, N);
    return 0;
}
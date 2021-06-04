#include <bits/stdc++.h>
template <typename T>
#define pb push_back

using namespace std;
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[y].pb(x);
        l[x].pb(y);
    }

    void BFS(T src)
    {
        map<T, bool> visited;

        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

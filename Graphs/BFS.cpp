
#include <bits/stdc++.h>

#define pb push_back

using namespace std;
template <typename T>
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

using namespace std;

int main()
{

    Graph<int> g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.BFS(1);
    return 0;
}
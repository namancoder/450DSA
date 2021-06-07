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

    void DFS()
    {
        map<T, bool> visited;

        for (auto nbr : l)
        {
            visited[nbr.first] = false;
        }
        int cnt = 0;

        for (auto p : l)
        {
            if (!visited[p.first])
            {
                cout << "COMPONEnt " << cnt << "-->";
                dfs_helper(p.first, visited);
                cnt++;
                cout << endl;
            }
        }
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        if (!visited[src])
        {
            visited[src] = true;
            cout << src << " ";
            for (auto nbr : l[src])
            {
                dfs_helper(nbr, visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.DFS();
    return 0;
}

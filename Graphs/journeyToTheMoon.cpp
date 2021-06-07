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

        // for (auto nbr : l)
        // {
        //     visited[nbr.first] = false;
        // }
        //int cnt = 0;

        long long count = 0, ans = 0;
        int v = 0;
        for (auto nbr : l)
        {
            v++;
        }
        cout << v << "--- " << endl;
        for (auto p : l)
        {
            if (!visited[p.first])
            {
                //cout << "COMPONEnt " << cnt << "-->";
                long long c = 0;
                dfs_helper(p.first, visited, c);
                ans += c * (v - c);
            };
        }

        cout << (ans / 2) << endl;
    }

    void dfs_helper(T src, map<T, bool> &visited, long long &c)
    {
        c++;
        // if (!visited[src])
        // {
        //     visited[src] = true;
        //     //cout << src << " ";
        //     for (auto nbr : l[src])
        //     {
        //         dfs_helper(nbr, visited, c);
        //     }
        // }
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (visited[nbr])
                continue;
            dfs_helper(nbr, visited, c);
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 9);

    g.DFS();
    return 0;
}

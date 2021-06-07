#include <bits/stdc++.h>
#define pb push_back
using namespace std;
template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        //l[y].pb(x);
        l[x].pb(y);
    }

    void DFS()
    {
        map<T, bool> visited;
        list<T> ordering;

        for (auto nbr : l)
        {
            visited[nbr.first] = false;
        }
        for (auto p : l)
        {
            if (!visited[p.first])
            {
                //     dfs_helper(p.first, visited);
                // }
                dfs_helper(p.first, visited, ordering);
            }
        }
        for (auto node : ordering)
        {
            cout << node << endl;
        }
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;
        //cout << src <<" ";
        for (auto nbr : l[src])
        {
            if (!visited[nbr])
                dfs_helper(nbr, visited, ordering);
        }
        ordering.push_front(src);
        return;
    }
};

int main()
{
    Graph<string> g;

    g.addEdge("Python", "DataPREP");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPREP", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("Dataset", "FaceRecogn");

    g.DFS();
    return 0;
}

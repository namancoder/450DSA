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



    void DFS(T src)
    {
        map<T, bool> visited;

        for (auto nbr : l)
        {
            visited[nbr.first] = false;
        }

        dfs_helper(src, visited);
    }

    void dfs_helper(T src , map<T,bool>  &visited)
    {
        if(!visited[src])
        {
        visited[src]= true;
        cout << src <<" ";
        for(auto nbr: l[src])
        {
            dfs_helper(nbr , visited);
        }
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);


    g.DFS(1);
    return 0;
}

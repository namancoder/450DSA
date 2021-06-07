#include <bits/stdc++.h>
#define pb push_back
using namespace std;
template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(int x, int y, bool directed = false)
    {
        l[x].pb(y);
        if (!directed)
            l[y].pb(x);
    }

    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;

        for(auto nbr: l[node]){
            if(!visited[nbr])
            {
                //visit the nbrs recursively
                bool isCycle = cycle_helper(nbr,visited,node);
                if(isCycle)
                return true;
                
            }
            else if(parent != nbr)
            { 
                return true;
            }
            
        }
        return false;
    }

    bool contains_cycle()
    {
        
        int V = 0;
        for (auto nbr : l)
            V++;
         bool visited[V];
       return cycle_helper(0, visited, -1);
    }

};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    //g.addEdge(8, 9);

    if(g.contains_cycle())
    cout << "YES"<<endl;
    else
    cout << "NO"<<endl;
    
    return 0;
}

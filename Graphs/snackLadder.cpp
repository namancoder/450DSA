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
        //l[y].pb(x);
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

int main()
{
    Graph<int> g;

    int board[50] = {0};

    board[2] =  13;
    board[5] =  2;
    board[9] =  18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j]

            if(j<=36)
            g.addEdge(i,j); 
        }
    }
    return 0;
}

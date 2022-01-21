#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    list<int> *l;
    int Vertices;

public:
    Graph(int v)
    {
        Vertices = v;
        l = new list<int>[Vertices];
    }

    void AddEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        // for every row
        for (int i = 0; i < Vertices; i++)
        {
            cout << i << "--> ";
            // iterating ith linked list
            for (auto node : l[i])
            {
                cout << node << ", ";
            }
            cout << endl;
        }
    }

    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[Vertices]{0};

        // push source in q
        q.push(source);

        visited[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";
            q.pop();

            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ", ";

        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }

        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[Vertices]{0};
        dfsHelper(source, visited);
    }

    void topologicalSort()
    {

        // create indegree vector, initiate w/ 0
        vector<int> inDegree(Vertices, 0);

        // fill values of in-degree of each node
        for (int i = 0; i < Vertices; i++)
        {
            for (auto nbr : l[i])
            {
                inDegree[nbr]++;
            }
        }

        // push nodes w 0 in-degree into a queue
        queue<int> q;
        for (int i = 0; i < Vertices; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        //while q isn't empty, keep priting front
        // and reduce in-degree of front's nbr by 1
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto nbr : l[node])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{


    // bfs, dfs input
    // Graph g(7);
    // g.AddEdge(1, 0);
    // g.AddEdge(4, 0);
    // g.AddEdge(1, 2);
    // g.AddEdge(2, 3);
    // g.AddEdge(4, 5);
    // g.AddEdge(4, 3);
    // g.AddEdge(5, 3);
    // g.AddEdge(5, 6);

    // g.printAdjList();
    // g.dfs(1);

    Graph ts(6);

    ts.AddEdge(1, 2, 0);
    ts.AddEdge(1, 4, 0);
    ts.AddEdge(0, 2, 0);
    ts.AddEdge(2, 3, 0);
    ts.AddEdge(3, 5, 0);
    ts.AddEdge(4, 5, 0);

    ts.topologicalSort();
    
    return 0;
}
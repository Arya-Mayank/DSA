#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> * l;

    public: 
    Graph(int vertices){
        V=vertices;
        l = new list<int>[V];
    }

    void insertKeys(vector<vector<int>> rooms){
        for(int i=0;i<rooms.size();i++){
            for(int key: rooms[i]){
                l[i].push_back(key);
            }
        }
    }

    void printAdjList()
    {
        // for every row
        for (int i = 0; i < V; i++)
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

    void traverse(int src, bool *visited){
        visited[src] = 1;

        for(auto nbr: l[src]){
            traverse(nbr, visited);
        }
    }
};

bool canVisitAllRooms(vector<vector<int>>& rooms) {
     // your code goes here
    Graph g(rooms.size());
    g.insertKeys(rooms);
    bool *visited = new bool[rooms.size()]{0};

    g.traverse(0, visited);

    for(int i= 0;i<rooms.size();i++){
        if(visited[i] == 0){
            return false;
        }
    }

    return true;
}

int main(){

    vector<vector<int>>rooms ={{1},{4,3},{},{},{}};
    cout << canVisitAllRooms(rooms);    
    

    return 0;
}
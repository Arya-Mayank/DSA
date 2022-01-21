#include<iostream>
#include<list>
#include<vector>
#include<set> 
using namespace std;

class Graph{

    int V;  // vertices
    list<pair<int,int>> *l;  //linked list of pairs<int, int>

    public: 
    Graph(int vertices){
        V = vertices;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int x, int y, int weight, bool undir=true){
        l[x].push_back({weight, y});
        if(undir){
            l[y].push_back({weight,x});
        }
    }

    int dijkstra(int src, int dest){

        //vector to track distance
        vector<int> distance(V, INT_MAX);

        //set to maintain pairs of node & dist
        set<pair<int,int>> s;

        distance[src] = 0;
        s.insert({0,src});

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);

            //traverse nbrs of found node
            for(auto nbrPair: l[node]){
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if(distTillNow + currentEdge < distance[nbr]){
                    //remove if node already exists
                    auto f = s.find({distance[nbr], nbr});
                    if(f!= s.end()){
                        s.erase(f);
                    }

                    // insert updated new pair
                    distance[nbr] = distTillNow + currentEdge;
                    s.insert({distance[nbr], nbr});

                }
            }
        }

        // Single Source Shortest Path to all nodes
        for(int i =0; i<V;i++){
            cout << "For node " << i << " distance is " << distance[i] << endl;
        }

        return distance[dest];
    }

};


int main(){

    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;

    return 0;
}
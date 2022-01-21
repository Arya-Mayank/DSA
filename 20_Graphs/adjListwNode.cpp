#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Graph;

class Node{
    string name;
    vector<string> nbrs;

    public:

    // constructor
    Node(string name){
        this->name = name;
    }

    friend Graph;
};

class Graph{
    unordered_map<string,Node*> m;

    public:

    // constructor
    Graph(vector<string> cities){
        for(auto city: cities){
            m[city] = new Node(city);
        }
    }

    void AddEdge(string x, string y, bool undir= false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void print(){
        for(auto cityPair: m){
            cout << cityPair.first << " --> ";

            for(auto nbr: cityPair.second->nbrs){
                cout << nbr << " ,";
            }
            cout << endl;
        }
    }
};


int main(){


    vector<string> cities = {"Delhi", "Paris", "New York", "London"};

    Graph g(cities);

    g.AddEdge("Delhi", "London");
    g.AddEdge("Delhi", "Paris");
    g.AddEdge("New York", "London");
    g.AddEdge("Paris", "New York");

    g.print();
    return 0;
}
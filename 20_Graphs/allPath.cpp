#include <bits/stdc++.h>

using namespace std;

void dfs(int src, vector<int> subSol, vector<list<int>> &l, vector<vector<int>> &sol){
    for(auto node: l[src]){
        subSol.push_back(node);
        dfs(node, subSol, l, sol);
        subSol.insert(subSol.begin(), 0);
        if(subSol.size()!=1){
            sol.push_back(subSol);
        }
        subSol.clear();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<list<int>> l(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            l[i].push_back(graph[i][j]);
        }
    }

    vector<vector<int>> sol;
    vector<int> subSol;

    dfs(0, subSol, l, sol);

    for(auto subsol : sol){
        for(auto num: subsol) {
            cout << num << " ";
        }
        cout << endl;
    }

    // for(auto list: l){
    //     for(auto node:list){
    //         cout << node << " ";
    //     }
    // }
}

int main()
{

    vector<vector<int>> graph = {{4,3,1}, {3,2,4}, {3}, {4}, {}};
    allPathsSourceTarget(graph);

    return 0;
}
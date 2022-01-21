#include <bits/stdc++.h>

using namespace std;

int findCenter(vector<vector<int>> &edges)
{
    int highest = INT_MIN;
    for(int i = 0; i < edges.size(); i++){
        for(int j=0;j<2;j++){
            highest = max(highest, edges[i][j]);
        }
    }

    vector<list<int>> nbrs(highest+1);

    for(int i=0;i<edges.size();i++){
        int first = edges[i][0];
        int second = edges[i][1];

        nbrs[first].push_back(second);
        nbrs[second].push_back(first);
    }

    int ans;
    int count=0;
    for(int i=1;i<nbrs.size();i++){
        int c=0;
        for(auto x: nbrs[i]){
            c++;
        }
        
        if(c>count){
            count = c;
            ans = i;
        }
    }

    return ans;
}

class Graph{
    
};

int main()
{

    vector<vector<int>> v = {{1, 2}, {2, 3}, {4, 2}};
    vector<vector<int>> v2 = {{1, 5}, {5, 6}, {5, 2},{5,3},{5,4}};

    cout << findCenter(v2);

    // int highest = INT_MIN;
    // for(int i = 0; i < v.size(); i++){
    //     for(int j=0;j<2;j++){
    //         highest = max(highest, v[i][j]);
    //     }
    // }

    // vector<list<int>> nbrs(highest+1);

    // for(int i=0;i<v.size();i++){
    //     int first = v[i][0];
    //     int second = v[i][1];

    //     nbrs[first].push_back(second);
    //     nbrs[second].push_back(first);
    // }

    // int ans;
    // int count=0;
    // for(int i=1;i<nbrs.size();i++){
    //     int c=0;
    //     for(auto x: nbrs[i]){
    //         c++;
    //     }
        
    //     if(c>count){
    //         count = c;
    //         ans = i;
    //     }
    // }

    // cout << ans;

    return 0;
}
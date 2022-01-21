#include<bits/stdc++.h>

using namespace std;

int gridWays(int i, int j, int m, int n){

    //base case
    if(i==m-1 and j==n-1){
        return 1;
    }

    // out of grid
    if(i==m or j==n){
        return 0;
    }

    //rec case
    int ans = gridWays(i+1,j,m,n) + gridWays(i,j+1,m,n);

    return ans;
}

int main(){

    cout << gridWays(0,0,5,5);

    return 0;
}
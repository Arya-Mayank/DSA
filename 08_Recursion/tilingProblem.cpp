#include<bits/stdc++.h>

using namespace std;

int tillingProblem(int n, int m){

    // base case
    if(n>=1 and n <m){
        return 1;
    }

    if(n==m){
        return 2;
    }

    // rec case
    return tillingProblem(n-m,m)+ tillingProblem(n-1,m);
}

int main(){
    cout << tillingProblem(4,3);
}
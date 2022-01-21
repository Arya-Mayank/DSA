#include<bits/stdc++.h>
using namespace std;

vector<int> m;

void helper(int n){
    if(n==0){
        return;
    }

    helper(n-1);
    m.push_back(n);
}

vector<int> increasingNumbers(int N) {
    m.clear();
    helper(N);
    return m;
}

int main() {
    increasingNumbers(5);
    for(auto x: m){
        cout << x << endl;
    }
}
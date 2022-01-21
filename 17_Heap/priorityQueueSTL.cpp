#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v = {26,18,36,1,8,37,17,13,6};
    priority_queue<int, vector<int>, greater<int>> heap;

    for(int x: v){
        heap.push(x);
    }

    while(!heap.empty()){
        cout << heap.top() << " ";
        heap.pop();
    }

    return 0;
}
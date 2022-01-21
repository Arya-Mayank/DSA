#include<bits/stdc++.h>
using namespace std;


int maxProduct(vector<int>& nums) {
    priority_queue<int> pq;

    for(int x : nums) {
        pq.push(x);
    }
    int ans =1;
    for(int i=0;i<2;i++){
        ans *= (pq.top()-1);
        pq.pop();
    }
    
    return ans;
}

int main(){

    vector<int> v = {3,4,5,2};
    
    cout << maxProduct(v);

    return 0;
}




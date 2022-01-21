#include<bits/stdc++.h>

using namespace std;

int minSetSize(vector<int>& arr) {
    map<int,int> mp;
    int n = arr.size();
    int half = n/2;
    int count =0;

    // get frequency of elements
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    priority_queue<int> pq;

    for(auto it: mp){
        pq.push(it.second);
    }

    while(n>half){
        n-=pq.top();
        pq.pop();
        count++;
    }

    return count;
}

int main(){

    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};

    minSetSize(arr);


    return 0;
}
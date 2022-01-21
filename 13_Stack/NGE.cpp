#include<bits/stdc++.h>
using namespace std;

vector<int> help(vector<int> arr, int n){
    stack<int> s;
    s.push(arr[n-1]);

    vector<int> sol(n,0);
    
    for(int i =n-1;i>=0;i--){

        while(!s.empty() and arr[i] >= s.top()){
            s.pop();
        }

        if(s.empty()){
            sol[i] = -1;
        }else{
            sol[i] = s.top();
        }

        s.push(arr[i]);
    }

    return sol;

}

vector<int> nextGreaterElement(vector<int> v){
        int n = v.size();
        
        return help(v, n);
}

int main(){

    vector<int> arr = {11,13,21,3};

    vector<int> NGE = nextGreaterElement(arr);

    for(auto x : NGE){
        cout << x<< " ";
    }

    return 0;
}
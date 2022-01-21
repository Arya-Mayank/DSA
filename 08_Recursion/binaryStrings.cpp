#include <bits/stdc++.h>
using namespace std;

vector<string> solution;

void helper(int n,string str, int i){

    if(i == n){
        solution.push_back(str);
        return;
    }

    string s1 = str;
    s1.push_back('0');
    helper(n,s1,i+1);

    if(i>0 && str[i-1] =='0'){
        str.push_back('1');
        helper(n,str,i+1);
    }
    else if(i==0){
        str.push_back('1');
        helper(n,str,i+1);
    }
    return;
}

vector<string> binaryStrings(int n){
    string empty;
    solution.clear();
    helper(n,empty, 0);
    return solution;
}

int main(){

    vector<string> ans = binaryStrings(3);
    for(auto x : ans){
        cout << x << endl;
    }
}
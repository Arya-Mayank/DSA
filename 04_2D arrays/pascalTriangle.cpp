#include<iostream>
#include<vector>
using namespace std;

int binomialCoeff(int n, int k){
    int res =1;

    if(n>n-k){
        k=n-k;
    }

    for(int i=0;i<k;i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}


vector<vector<int>> printPascal(int n){
    vector<vector<int>> result;
    for (int line =0; line <n ; line++){
        vector<int> arr;
        for(int i=0; i<=line; i++){
           arr.push_back(binomialCoeff(line,i));
        }
    result.push_back(arr);   
    }
    return result;
}


int main(){

    vector<vector<int>> m = printPascal(5);

    for(int i = 0;i<m.size();i++){
        for(int j =0; j < m[i].size();j++){
            cout << m[i][j] ;
        }
        cout << endl;
    }
}
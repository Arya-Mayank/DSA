#include<bits/stdc++.h>

using namespace std;

void fillArray(int *arr, int i, int n, int val){

    //base case
    if(i==n){
        // print arr

        for(int i =0;i<n;i++){
            cout << arr[i] << " ";
        }

        return;
    }

    // rec case
    arr[i] = val;
    fillArray(arr, i+1, n, val+1);

    //backtracking
    arr[i] *= -1;
}

int main(){
    int arr[100] = {0};
    fillArray(arr,0,5,1);

    cout << endl;
    for(int x=0;x<5;x++){
        cout << arr[x] << " ";
    }
    return 0;
}
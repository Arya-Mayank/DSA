#include<iostream>

using namespace std;

bool isSorted(int arr[], int n){

    //base case
    
    if(n==1){
        return true;
    }

    //rec case
    if(arr[0]<arr[1] and isSorted(arr+1,n-1)){
        return true;
    }
    return false;

}

int main(){

    int arr[] = {2,5,17,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << isSorted(arr,n);
    return 0;
}
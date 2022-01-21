#include<iostream>

using namespace std;

int firstOcc(int arr[], int n, int key){
    //base case
    if(n==0){
        return -1;
    }

    // rec case
    if(arr[0]==key){
        return 0;
    }

    int subIndex = firstOcc(arr+1,n-1, key);
    if(subIndex>=0){
        return subIndex+1;
    }
    else return -1;
}

int lastOcc(int arr[], int n, int key){
    // base case
    if(n==0){
        return -1;
    }

    int subIndex = lastOcc(arr+1,n-1,key);
    if(subIndex ==-1){
        if(arr[0] == key){
            return 0;
        }
        else return -1;
    }
    else return subIndex+1;
}

int main(){

    int arr[]= {2,5,4,3,6,5,6,3,2};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout << lastOcc(arr,n,2);

    return 0;
}
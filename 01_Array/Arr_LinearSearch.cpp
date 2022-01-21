#include<iostream>

using namespace std;

// time complexity = O(N) at worst case

int linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[]={10,32,14,7,99,76,35,29,2};
    int n, key;

    n = sizeof(arr)/sizeof(int);

    cout << "Enter the element to find: ";
    cin >> key;

    int index = linearSearch(arr,n,key);

    if(index!= -1){
        cout << key << " found at index " << index << endl;
    }
    else cout << key << " NOT found";

    return 0;
}
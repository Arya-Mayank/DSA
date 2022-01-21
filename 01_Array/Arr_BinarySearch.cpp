#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int key){
    int start =0;
    int end = n-1;

    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }else end=mid-1;
    }
    return -1;
}

int main(){

    int arr[] = {2,4,6,8,10,12,14,16};
    int n, key;

    n = sizeof(arr)/sizeof(int);

    cout << "enter element to find: ";
    cin >> key;

    int index = binarySearch(arr,n,key);

    if(index!=-1){
        cout << key << " found at index " << index << endl;
    }
    else cout << key << " NOT found" << endl;

    return 0;
}
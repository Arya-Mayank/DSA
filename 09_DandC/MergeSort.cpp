#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int s, int e){
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    vector<int> temp;

    //compare the two halves and fill temp
    while(i<=m and j<=e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // fill remaining elements
    while(i<=m){
        temp.push_back(arr[i++]);
    }

    while(j<=e){
        temp.push_back(arr[j++]);
    }

    //copy the final temp back to original arr and return

    int k=0;
    for(int index = s; index <=e; index++){
        arr[index] = temp[k++];
    }

    return;
}


void mergeSort(vector<int> &arr, int start, int end){
    
    //base case
    if(start>=end){
        return;
    }

    //rec case
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    return merge(arr, start, end);
}

int main(){

    vector<int> array = {2,5,1,7,1,4,8,3,78,5,4,2,57,3,2,75,3};

    mergeSort(array, 0, 16);

    for(int x: array){
        cout<< x << " ";
    }

    return 0;
}
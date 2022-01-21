#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int start, int end){
    int i = start -1;
    int pivot = a[end];

    for(int j = start; j < end; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[end]);
    return i+1;
}

void quickSort(vector<int> &a, int start, int end){

    // base case
    if(start>=end){
        return;
    }

    // rec case
    int p = partition(a, start, end);
    quickSort(a, start, p-1);
    quickSort(a, p+1, end);
}

int main(){

    vector<int> arr = {3,5,1,6,8,2,4,7,8,10,6};
    quickSort(arr, 0, 10);

    for(int x: arr){
        cout << x << ' ';
    }

    return 0;
}
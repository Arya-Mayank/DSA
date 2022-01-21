#include<iostream>
using namespace std;

int prefixSum(int arr[], int n){

    int prefix[n] = {0};
    prefix[0] = arr[0];

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    int largestSum =0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int subArraySum = i>0? prefix[j] - prefix[i-1]: prefix[j];
            largestSum = max(largestSum,subArraySum);
        }
    }
    return largestSum;
}


int main(){

    int arr[] = {2,5,6,-12,5,-3,8,2,-3};
    int n = sizeof(arr)/sizeof(int);

    cout << prefixSum(arr, n);

    return 0;
}
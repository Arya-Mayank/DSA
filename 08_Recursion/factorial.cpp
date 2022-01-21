#include <iostream>

using namespace std;

int fact(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    // rec case
    int ans = n * fact(n - 1);
    return ans;
}

int fib(int n)
{

    // base case
    if (n == 0 or n == 1)
    {
        return n;
    }

    // rec case
    int f1 = fib(n - 1);
    int f2 = fib(n - 2);
    return f1 + f2;
}

bool isSorted(int arr[], int i, int n)
{

    //base case
    if (i == n - 1)
    {
        return true;
    }

    // rec case
    if (arr[i] < arr[i + 1] and isSorted(arr, i + 1, n))
    {
        return true;
    }
    return false;
}

// int main()
// {

//     int arr[] = {1, 2, 3, 49, 5, 6};
//     int n = sizeof(arr) / sizeof(int);

//     cout << isSorted(arr, 0, n) << endl;

//     cout << fact(5) << endl;
//     cout << fib(7) << endl;
//     return 0;
// }


void dec(int n){

    //base case
    if(n==0){
        return;
    }

    cout << n << ", ";
    dec(n-1);
}

void inc(int n){

    //base case
    if(n == 0){
        return;
    }

    inc(n-1);
    cout << n << ", ";
}

int firstOccurence(int arr[], int n, int key){

    //base case
    if(n==0){
        return -1;
    }

    //rec case
    if(arr[0]==key){
        return 0;
    }
    int subIndex = firstOccurence(arr+1,n-1,key);
    if(subIndex!=-1){
        return subIndex+1;
    }
    return -1;
}

int main(){

    int arr[] = {3,4,5,89,6,3,2,62};
    int n =sizeof(arr)/sizeof(int);
    cout << firstOccurence(arr,n,89);
    return 0;
}
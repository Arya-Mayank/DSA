#include<iostream>

using namespace std;

int fib(int n){
    //base case
    if(n==0 or n==1){
        return n;
    }

    //rec case
    int f1 = fib(n-1);
    int f2 = fib(n-2);
    return f1+f2;
}

int main(){

    cout << fib(5);

    return 0;
}
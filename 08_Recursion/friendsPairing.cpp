#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n){
        //base case 
    if(n==1 || n==2){
        return n;
    }

    //rec case

    return friendsPairing(n-1) + (n-1)*friendsPairing(n-2);
}


int main(){

    cout << friendsPairing(4);

    return 0;
}
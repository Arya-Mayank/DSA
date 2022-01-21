#include<iostream>
using namespace std;

int power(int n, int p){
    //base case
    if(p==0){
        return 1;
    }

    //rec case
    return n*power(n,p-1);
}

int fastPower(int n, int p){
    //base case
    if(p==0){
        return 1;
    }

    int subPower = fastPower(n,p/2);
    int subPowerSq = subPower*subPower;

    if(p&1){
        return n*subPowerSq;
    } return subPowerSq;
}


int main(){
    cout << power(2,10) <<endl;
    cout << fastPower(2,10);
    return 0;
}
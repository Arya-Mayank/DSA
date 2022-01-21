#include<iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    if(n&0 == 0){
        cout << "Odd";
    }else{
        cout << "Even";
    }

    return 0;
}
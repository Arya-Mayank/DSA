#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int i = 1;
    int count =0;
    while(i<=n){
        n-=i;
        i++;
        count++;
    }

    cout << count;
    return 0;
}
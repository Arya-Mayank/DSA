#include<bits/stdc++.h>

using namespace std;

void help(int min, int max, int step){

    for(int i=min;i<=max;i+=step){
        float value = (5.0/9.0)*(i-32);
        cout << i << " " << (int)value << endl;

    }
}

int main(){

    help(0,100,20);
    return 0;
}
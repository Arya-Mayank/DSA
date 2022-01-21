#include<iostream>

using namespace std;

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void stringSpell(int n){
    //base case 
    if(n==0){
        return;
    }

    int last = n%10;
    stringSpell(n/10);
    cout << spell[last] << " ";
}

int main(){
    stringSpell(2021);
    return 0;
}
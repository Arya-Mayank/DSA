#include<bits/stdc++.h>
using namespace std;

string vowel(string S){
    string C;
    for(int i=0;i<S.length();i++){
        if(S[i] == 'a' or S[i] == 'e' or S[i] == 'i' or S[i] == 'o' or S[i] == 'u')
        {
            C+=S[i];
        }
    }
    return C;
} 

int main(){

    string s1 = "hello";
    vowel(s1);
    return 0;
}
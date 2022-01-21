#include <iostream>
#include <string>
#include<cmath>
using namespace std;
 
int binaryToDecimal(string s)
{
    int result = 0;
    for(int i=s.length()-1; i>=0;i--){
        if(s[i]=='1'){
            result += pow(2,(s.length()-i-1));
        }
    }
    return result;
}

int main(){

    string s1 = "1111";
    binaryToDecimal(s1);
    return 0;
}
 
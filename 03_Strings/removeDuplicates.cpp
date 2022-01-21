#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

string removeDuplicate(string s)
{
    sort(s.begin(),s.end());
    string C;
    for(int i =0;i<s.length();i++){
        C+=s[i];
        while(i<s.length() and s[i]==s[i+1]){
            i++;
        }
    }

    return C;
    
}

int main()
{
    string s1 = "geeksforgeeks";
    cout << removeDuplicate(s1);
    return 0;
}
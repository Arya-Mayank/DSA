#include <bits/stdc++.h>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){
    int charCount[CHAR_MAX] = {0};
    queue<char> q;
    vector<char> solution;

    for(int i =0;i<str.size();i++){

        q.push(str[i]);
        charCount[str[i] - 'a']++;

        while(!q.empty()){
            if(charCount[str[i] - 'a'] > 1){
                q.pop();
            }else{
                solution.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            solution.push_back('0');
        }
    }

    return solution;

}

int main(){

    vector<char> str = {'a', 'a', 'b', 'c'};
    vector<char> sol = firstnonrepeating(str);

    for(auto x : sol){
        cout << x << " ";
    }

    return 0;
}
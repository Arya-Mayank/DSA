#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    // your code goes here
    priority_queue<int> pq;
    vector<string> ans(score.size(),"");

    for(int i = 0; i < score.size(); i++){
        pq.push(score[i]);
    }

    int j=0;

    vector<string> ranks = {"Gold Medal" , "Silver Medal", "Bronze Medal"};

    while(j<3){
        int current = pq.top();
        auto it = find(score.begin(), score.end(), current);
        int idx = it - score.begin();
        
        ans[idx] = ranks[j];
        
        j++;
        pq.pop();
    }

    for(int i=3; i<score.size(); i++){
        int current = pq.top();
        auto it = find(score.begin(), score.end(), current);
        int idx = it - score.begin();

        ans[idx] = to_string(i+1);
        pq.pop();
    }
    
    return ans;

}

int main(){
    vector<int> score = {2,3,5,1,4};
    vector<string> ans = findRelativeRanks(score);
    for(auto x: ans){
        cout << x << " ";
    }
}
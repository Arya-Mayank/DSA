#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> solution;

bool compare(vector<int> a, vector<int> b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

void help(vector<int> subset, vector<int>nums, int i, int n){
    if(i==n){
        for(auto x:solution){
            if(x==subset){
                return;
            }
        }
        
        solution.push_back(subset);
        return;
    }

    //ith element not being considered
    help(subset, nums, i+1, n);

    //ith element being considered
    subset.push_back(nums[i]);
    help(subset, nums, i+1, n);
    //backtrack
    subset.pop_back();
    
}

vector<vector<int>> uniqueSubsets(vector<int> nums){
    vector<int> empty;
    empty.clear();
    int n = nums.size();

    help(empty, nums, 0, n);
    sort(solution.begin(), solution.end());
    return solution;
}

int main(){

    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = uniqueSubsets(nums);

    for(auto x: ans){
        for(auto i : x){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
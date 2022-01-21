#include<bits/stdc++.h>

using namespace std;

int help(vector<int> coins, int amount, vector<int>dp){
    
    //base cases
        //change not possible
    if(amount < 0 ){
        return -1;
    }
        // zero coins needed
    if(amount == 0){
        return 0;
    }

    // dp : avoid re calculation
    if(dp[amount] != 0){
        return dp[amount];
    } 

    //rec case
    int minimum = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int val = help(coins, amount-coins[i], dp);
        if (val >=0 and val<minimum){
            minimum = val+1;
        }
    }
    dp[amount] = (minimum == INT_MAX)? -1: minimum;
    return dp[amount];
}

int minCoin(vector<int> coins, int amount){

    vector<int> dp(amount+1, 0);

    int ans = help(coins,amount,dp);

    return ans;
}

int main(){

    vector<int> coins= {1,3,7,10};
    int amount =15;

    cout << minCoin(coins, amount);
    return 0;
}
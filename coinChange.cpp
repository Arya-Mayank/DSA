#include<bits/stdc++.h>

using namespace std;

int minNumberOfCoins(int money, vector<int> denoms){

    vector<int> dp(money+1,0);
    dp[0] = 0;
    
    for(int i=1;i<=money;i++){
        dp[i] = INT_MAX;
        for(auto denom : denoms){
            if(i - denom >=0 and dp[i-denom] != INT_MAX){
                dp[i] = min(dp[i], dp[i-denom]+1);
            }
        }
    }
    return dp[money]==INT_MAX?-1:dp[money];
}

int main(){

    vector<int> denoms = {1,3,7,10};
    int money = 8;

    cout<< minNumberOfCoins(money,denoms);

}
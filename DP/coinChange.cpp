#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve1(vector<int> coins,int coin){
    if(coin==0){
        return 0;
    }
    if(coin<0){
        return INT_MAX-1;
    }
    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        ans = min(ans,solve1(coins,coin-coins[i]) + 1);
    }
    return ans;
}

int solve2(vector<int> coins,int coin,vector<int> &dp){
    if(coin==0){
        return 0;
    }
    if(coin<0){
        return INT_MAX-1;
    }
    if(dp[coin]!=-1){
        return dp[coin];
    }

    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        ans = min(ans,solve2(coins,coin-coins[i],dp) + 1);
    }
    return dp[coin] = ans;
}

int solve3(vector<int> coins,int coin){
    vector<int> dp(coin+1,INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=coin; i++){
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j] >= 0 and dp[i-coins[j]]!=INT_MAX) 
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
        }
    }
    return dp[coin];
}

int main(){
    vector<int> coins = {1,2,3};
    int coin = 9;
    // int ans = solve1(coins,coin);
    // vector<int> dp(coin+1,-1);
    // int ans = solve2(coins,coin,dp);
    int ans = solve3(coins,coin);
    if(ans==INT_MAX){
        cout<<"Ans : -1"<<endl;
    }
    else{
        cout<<"Ans: "<<ans<<endl;
    }
    return 0;
}
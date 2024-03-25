#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve1(vector<int> coins, int X){
    if(X==0){
        return 0;
    }
    if(X<0){
        return INT_MAX - 1;
    }
    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = 1 + solve1(coins,X-coins[i]);
        mini = min(mini,ans);
    }
    return mini;
}

int solve2(vector<int> coins,int X,vector<int> &dp){
    if(X==0){
        return 0;
    }
    if(X<0){
        return INT_MAX - 1;
    }

    if(dp[X] != -1) return dp[X];

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = 1 + solve2(coins,X-coins[i],dp);
        mini = min(mini,ans);
    }

    dp[X] = mini;
    return mini;
}


int main(){
    vector<int> coins = {1,2,3};
    int target = 7;
    int n = target;

    // int ans = solve1(coins,target);

    vector<int> dp(n+1,-1);
    int ans = solve2(coins,target,dp);
    cout<<ans;
    return 0;
}
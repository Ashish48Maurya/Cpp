#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve1(vector<int> cost,int n){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    return cost[n] + (min(solve1(cost,n-1) , solve1(cost,n-2)));
}

int solve2(vector<int> cost,int n, vector<int> &v){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    v[n] =  cost[n] + (min(solve1(cost,n-1) , solve1(cost,n-2)));
    return v[n];
}

int solve3(vector<int> cost,int n, vector<int> &dp){
    
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2; i<=n; i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return dp[n];
}

int solve4(vector<int> cost, int n){
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i=2; i<=n; i++){
        int curr = cost[i] + min(prev1,prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    vector<int> cost = {1,100,2,30,4,7}; // You have to Reach to the (N-1)th step (Consider cost of (N-1)th step also)
    int n = cost.size(); 
    // int ans = solve1(cost,n-1);

    // vector<int> v(n+1,-1);
    // int ans = solve2(cost,n-1,v);

    // vector<int> dp(n);
    // int ans = solve3(cost,n-1,dp);

    vector<int> dp(n);
    int ans = solve4(cost,3);
    cout<<ans<<endl;
    return 0;
}
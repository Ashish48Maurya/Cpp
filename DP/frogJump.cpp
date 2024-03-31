#include<bits/stdc++.h>
using namespace std;
int solve1(int n,vector<int> path){
    if(n==0){
        return 0;
    }
    int moveby1,moveby2 = INT_MAX;

    moveby1 = solve1(n-1,path) + abs(path[n-1]-path[n]);
    if(n>1)
    moveby2 = solve1(n-2,path) + abs(path[n-2]-path[n]);

    return min(moveby1,moveby2);
}

int solve2(int n,vector<int> path, vector<int> &dp){
    dp[0] = 0;

    if(dp[n]!=-1){
        return dp[n];
    }

    int moveby1,moveby2 = INT_MAX;
    moveby1 = solve1(n-1,path) + abs(path[n-1]-path[n]);
    if(n>1)
    moveby2 = solve1(n-2,path) + abs(path[n-2]-path[n]);

    return dp[n] = min(moveby1,moveby2);
}

int solve3(int n,vector<int> path){
    int length = path.size();
    vector<int> dp(length,0);
    dp[0] = 0;

    int moveby1,moveby2 = INT_MAX;
    for(int i=1; i<length; i++){
        moveby1 = dp[n-1] + abs(path[n-1]-path[n]);
        if(n>1)
        moveby2 = dp[n-2] + abs(path[n-2]-path[n]);
        
        dp[i] = min(moveby1,moveby2);
    }

    return dp[n-1];
}

int main(){
    vector<int> path = {10,20,30,10};
    int n = path.size();
    // cout<<solve1(n-1,path);

    // vector<int> dp(n,-1);
    // cout<<solve2(n-1,path,dp);

    cout<<solve3(n-1,path);
    return 0;
}
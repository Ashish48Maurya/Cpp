#include<bits/stdc++.h>
using namespace std;

int solve1(int n,int m){
    if(n==0 and m==0) return 1;
    if(n<0 or m<0) return 0;

    int up = solve1(n-1,m);
    int left = solve1(n,m-1);

    return up+left;
}

int solve2(int n,int m,vector<vector<int>> &dp){
    if(n==0 and m==0) return 1;
    if(n<0 or m<0) return 0;

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    int up = solve1(n-1,m);
    int left = solve1(n,m-1);

    return dp[n][m] = up+left;
}

int solve3(int n,int m){
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int up = 0, left = 0;
            if(i == 0 && j == 0) 
                dp[i][j] = 1;

            if(i > 0) 
                up = dp[i - 1][j];
            if(j > 0) 
                left = dp[i][j - 1];
            
            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1];
}

int main(){
    int n,m;
    cin>>n>>m;
    // cout<<solve1(n-1,m-1); //U have to reach to the grid[0][0] from grid[n-1][m-1];

    vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<solve2(n-1,m-1,dp);

    cout<<solve3(n,m);
    return 0;
}
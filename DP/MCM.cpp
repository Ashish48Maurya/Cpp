#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve1(int i,int j, vector<int> v){
    if(i==j or i+1==j) return 0;
    int mini = INT_MAX;
    for(int k=i+1; k<j; k++){
        int select = v[i]*v[k]*v[j] + solve1(i,k,v) + solve1(k,j,v);
        mini = min(mini,select);
    }
    return mini;
}


int solve2(int i,int j, vector<int> v,vector<vector<int>> &dp){
    if(i==j or i+1==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini = INT_MAX;
    for(int k=i+1; k<j; k++){
        int select = v[i]*v[k]*v[j] + solve1(i,k,v) + solve1(k,j,v);
        mini = min(mini,select);
    }
    return dp[i][j] = mini;
}

int solve3(int i,int j, vector<int> v){
    int n = v.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int mini = INT_MAX;
    for(int k=i+1; k<j; k++){
            int select = v[i]*v[k]*v[j] + dp[i][k] + dp[k][j];
            mini = min(mini,select);
    }
    return dp[i][j] = mini;
}


int main(){
    vector<int> v = {4,3,1,6,2};
    int i = 0;
    int j = v.size()-1;
    int n = v.size();
    
    // cout<<solve1(i,j,v);

    vector<vector<int>> dp(n,vector<int> (n,-1));
    cout<<solve2(i,j,v,dp);
    return 0;
}
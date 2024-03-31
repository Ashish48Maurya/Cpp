#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve1(vector<int> w, vector<int> p, int W, int index){
    if(index==0){
        if(W>=w[0]){
            return p[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(W>=w[index]){
        include = p[index] + solve1(w,p,W-w[index],index-1);
    }

    int exclude = 0 + solve1(w,p,W,index-1);
    return max(include,exclude);
    
}

int solve2(vector<int> w,vector<int> p,int W,int index, vector<vector<int>> &dp){
    if(index==0){
        if(W>=w[0]){
            return p[0];
        }
        else{
            return 0;
        }
    }

    if(dp[index][W]!=-1){
        return dp[index][W];
    }

    int include = 0;
    if(W>=w[index]){
        include = p[index] + solve1(w,p,W-w[index],index-1);
    }

    int exclude = 0 + solve1(w,p,W,index-1);
    dp[index][W] = max(include,exclude);
    return dp[index][W];
}

int solve3(vector<int> w,vector<int> p, int W, int n){
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i = w[0]; i<=W; i++){
        if(i>=w[0]){
            dp[0][i] = p[0];
        }
        else{
            dp[0][i] = 0;
        }
    }

    for(int index=1; index<n; index++){
        for(int i=0; i<=W; i++){
        int include = 0;
        if(i>=w[index]){
            include = p[index] + dp[index-1][i-w[index]];
        }

        int exclude = 0 + dp[index-1][i];
        dp[index][i] = max(include,exclude);
        }
    }
    return dp[n-1][W];
}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> profit = {5,4,8,6};
    int n = weight.size();
    int maxWeight = 5;
    // cout<<solve1(weight,profit,maxWeight,n-1);

    // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // cout<<solve2(weight,profit,maxWeight,n-1,dp);

    cout<<solve3(weight,profit,maxWeight,n);

    return 0;
}
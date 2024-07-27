#include<bits/stdc++.h>
using namespace std;

int solve1(string str1,string str2,int a,int b){
    if(a==str1.length() || b==str2.length()){
        return 0;
    }
    int ans = 0;
    if(str1[a]==str2[b]){
        ans = 1+solve1(str1,str2,a+1,b+1);
    }
    else{
        ans = max(solve1(str1,str2,a+1,b),solve1(str1,str2,a,b+1));
    }
    return ans;
}

int solve2(string str1,string str2,int a,int b,vector<vector<int>> dp){
    if(a==str1.length() || b==str2.length()){
        return 0;
    }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    int ans = 0;
    if(str1[a]==str2[b]){
        ans = 1+solve2(str1,str2,a+1,b+1,dp);
    }
    else{
        ans = max(solve2(str1,str2,a+1,b,dp),solve2(str1,str2,a,b+1,dp));
    }
    return dp[a][b] = ans;
}

int solve3(string str1,string str2,int a,int b){
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    for(int i=a-1; i>=0; i--){
        for(int j=b-1; j>=0; j--){
            int ans = 0;
            if(str1[i]==str2[j]){
            ans = 1+dp[i+1][j+1];
            }
            else{
            ans = max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int main(){
    string str1 = "abaaba";
    string str2 = "babbab";
    // int ans = solve1(str1,str2,0,0);
    vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,-1));
    // int ans = solve2(str1,str2,0,0,dp);
    int ans = solve3(str1,str2,str1.length(),str2.length());
    cout<<ans;
    return 0;
}
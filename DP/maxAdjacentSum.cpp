#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findMax1(vector<int> arr,int n){//starting from right
    if(n==0){
        return arr[0];
    }
    if(n<0){
        return 0;
    }
    int included = arr[n] + findMax1(arr,n-2);
    int excluded = 0 + findMax1(arr,n-1);
    return max(included,excluded);
}

int findMax2(vector<int> arr,int n,vector<int> dp){//starting from right
    if(n==0){
        return arr[0];
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    int included = arr[n] + findMax2(arr,n-2,dp);
    int excluded = 0 + findMax2(arr,n-1,dp);

    dp[n] = max(included,excluded);
    return max(included,excluded);
}

int findMax3(vector<int> arr,int n){//starting from right
    vector<int> dp(n,0);
    dp[0] = arr[0];
    
    for(int i=2; i<n; i++){
        int included = arr[i] + dp[i-2];
        int excluded =  0+dp[i-1];
        dp[i] = max(included, excluded);
    }

    return dp[n-1];
}

int findMax4(vector<int> arr,int n){//starting from right
    int prev1 = arr[0];
    int prev2 = 0;
    
    for(int i=1; i<n; i++){
        int included = arr[i] + prev2;
        int excluded = 0 + prev1;
        int curr = max(included,excluded);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main(){
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    // int ans = findMax1(arr,n-1);

    // vector<int> dp(n+1,-1);
    // int ans = findMax2(arr,n-1,dp);

    int ans = findMax4(arr,n);
    cout<<ans<<endl;
    return 0;
}
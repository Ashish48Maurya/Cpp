#include<iostream>
#include<vector>
using namespace std;

int solve1(vector<int> weight,vector<int> profit,int index,int maxWeight){
    //Case for handling 1st element
    if(index==0){
        if(weight[0] <= maxWeight){
        return profit[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(maxWeight >= weight[index]){
        include = profit[index] + solve1(weight,profit,index-1,maxWeight-weight[index]);
    }
    int exclude = solve1(weight,profit,index-1,maxWeight);

    return max(include,exclude);
}

int solve2(vector<int> weight,vector<int> profit,int index,int maxWeight,vector<vector<int>> &dp){
    if(index==0){
        if(weight[0] <= maxWeight){
        return profit[0];
        }
        else{
            return 0;
        }
    }

    if(dp[index][maxWeight]!=-1){
        return dp[index][maxWeight];
    }

    int include = 0;
    if(maxWeight >= weight[index]){
        include = profit[index] + solve2(weight,profit,index-1,maxWeight-weight[index],dp);
    }
    int exclude = solve2(weight,profit,index-1,maxWeight,dp);

    return dp[index][maxWeight] = max(include,exclude);
}

int solve3(vector<int> weight,vector<int> profit,int n,int maxWeight){
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
    for(int i=0; i<=maxWeight; i++){
        if(weight[0] <= maxWeight){
        dp[0][i] = profit[0];
        }
        else{
            dp[0][i] = 0;
        }
    }

    for(int index=1; index<n; index++){
        for(int capacity=0; capacity<=maxWeight; capacity++){
            int include = 0;
            if(capacity >= weight[index]){
                include = profit[index] + dp[index-1][capacity-weight[index]];
            }
            int exclude = 0 + dp[index-1][capacity];
            dp[index][capacity] = max(include,exclude);
        }
    }
    return dp[n-1][maxWeight];
}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> profit = {5,4,8,6};
    int n = weight.size();
    int maxWeight = 5;

    // int ans = solve1(weight,profit,n-1,maxWeight);

    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // int ans = solve2(weight,profit,n-1,maxWeight,dp);

    int ans = solve3(weight,profit,n,maxWeight);
    cout<<ans;
    return 0;
}
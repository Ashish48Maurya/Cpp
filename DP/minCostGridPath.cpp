#include<bits/stdc++.h>
using namespace std;

int solve1(int row, int column, vector<vector<int>> gridWithCost){
    if(row==0 and column==0){
        return gridWithCost[0][0];
    }
    if(row<0 || column<0) return 1e8; //return any bigInt Value don't use INT_MAX, because if you use 

    int up = gridWithCost[row][column] + solve1(row-1, column, gridWithCost);
    int left = gridWithCost[row][column] + solve1(row,column-1,gridWithCost);

    return min(up,left);
}

int solve2(int row,int column, vector<vector<int>> gridWithCost, vector<vector<int>> &dp){
    if(row==0 and column==0) return gridWithCost[0][0];
    if(row<0 || column<0) return 1e8;

    if(dp[row][column]!=-1) return dp[row][column];

    int up = gridWithCost[row][column] + solve2(row-1,column,gridWithCost,dp);
    int left = gridWithCost[row][column] + solve2(row,column-1,gridWithCost,dp);

    return dp[row][column] = min(up,left);
}

int solve3(int row,int column, vector<vector<int>> grid){
    vector<vector<int>> dp(row,vector<int> (column,0));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(i==0 and j==0) dp[i][j] = grid[i][j];

            int left = 1e8,up=1e8;
            if(i>0) up = grid[row][column] + dp[i-1][j];
            if(j>0) left = grid[row][column] + dp[i][j-1];

            dp[i][j] = min(left,up);
        }
    }
    return dp[row-1][column-1];
}
int main(){
    int n = 3; 
    int m = 3;  
    vector<vector<int>> gridWithCost = {{1,2,3},{4,5,4},{7,5,9}}; //Taking 3*3 Matrix
    // cout<<solve1(n-1,m-1,gridWithCost);

    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<solve2(n-1,m-1,gridWithCost,dp);

    cout<<solve3(n,m,gridWithCost);
    return 0;
}
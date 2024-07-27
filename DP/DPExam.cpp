//LCS
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


//FloydWarshall
#include<bits/stdc++.h>
using namespace std;

void floydW(vector<vector<int>> matrix){
    int V = matrix.size(); //No. Of Nodes
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(matrix[i][j] == -1){
                matrix[i][j]=1e8;
            }
        }
    }

    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int ans = matrix[i][j]==1e8 ? -1:matrix[i][j];
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> matrix = {{0,8,-1,1},{-1,0,1,-1},{4,-1,0,-1},{-1,2,9,0}};
    floydW(matrix);
    return 0;
}


//BellmanFord
#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> adjList, int S, int V){
    vector<int> dist(V,1e8);
    dist[S] = 0;
    for(int i=0; i<V-1; i++){
        for(auto element : adjList){
            int u = element[0]; //from
            int v = element[1]; //to
            int w = element[2]; //cost required for travelling from u to v

            if(dist[u]!=1e8 and dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }

    //to detect cycle traverse one more time
    for(auto element:adjList){
       int u = element[0]; //from
       int v = element[1]; //to
       int w = element[2]; //cost required for travelling from u to v
       if(dist[u]!=1e8 and dist[u]+w < dist[v]){
           return {-1};
       }
    }
    return dist;
}

int main(){
    int V = 6;  //No of Vertex(Node)
    int S = 0;
    vector<vector<int>> adjList = {{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
    vector<int> ans = bellmanFord(adjList,S,V);
    for(auto i : ans){
       cout<<i<<" ";
    }
    return 0;
}


//MCM
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


//CoinChange
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve1(vector<int> coins,int coin){
    if(coin==0){
        return 0;
    }
    if(coin<0){
        return INT_MAX-1;
    }
    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        ans = min(ans,solve1(coins,coin-coins[i]) + 1);
    }
    return ans;
}

int solve2(vector<int> coins,int coin,vector<int> &dp){
    if(coin==0){
        return 0;
    }
    if(coin<0){
        return INT_MAX-1;
    }
    if(dp[coin]!=-1){
        return dp[coin];
    }

    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        ans = min(ans,solve2(coins,coin-coins[i],dp) + 1);
    }
    return dp[coin] = ans;
}

int solve3(vector<int> coins,int coin){
    vector<int> dp(coin+1,INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=coin; i++){
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j] >= 0 and dp[i-coins[j]]!=INT_MAX) 
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
        }
    }
    return dp[coin];
}

int main(){
    vector<int> coins = {1,2,3};
    int coin = 9;
    // int ans = solve1(coins,coin);
    // vector<int> dp(coin+1,-1);
    // int ans = solve2(coins,coin,dp);
    int ans = solve3(coins,coin);
    if(ans==INT_MAX){
        cout<<"Ans : -1"<<endl;
    }
    else{
        cout<<"Ans: "<<ans<<endl;
    }
    return 0;
}


//KnapSack
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



//Graph Coloring
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node,int color[], vector<vector<int>> graph,int N,int col){
    for(int k=0; k<N; k++){
        if(graph[k][node]==1 and color[k]==col){
            return false;
        }
    }
    return true;
}

bool solve(int node,int color[], int m, int N, vector<vector<int>> graph){
    if(node==N)return true;
    for(int i=1; i<=m; i++){    //try all the colors;
        if(isSafe(node,color,graph,N,i)){
            color[node] = i;
            if(solve(node+1,color,m,N,graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main(){
    int N = 4;
    vector<vector<int>> graph = {{0,1,1,1},{1,0,1,1},{1,1,0,0},{1,1,0,0}};
    int m = 3; //color array size
    int color[N] = {0}; //initially all the nodes are colorless
    if(solve(0,color,m,N,graph)) cout<<"Possible";
    else{
        cout<<"Not Possible";
    }
}
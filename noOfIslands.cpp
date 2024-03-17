#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void numberOfIslands(int row, int col, vector<vector<int>> graph, vector<vector<int>> &visited){
    visited[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    int n = graph.size();
    int m = graph[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        for(int delrow=-1; delrow<=1; delrow++){
        for(int delcol=-1; delcol<=1; delcol++){
            int nrow = row + delrow;
            int ncol = col + delcol;
            if(nrow<n and nrow>=0 and ncol<m and ncol>=0 and graph[nrow][ncol]==1 and visited[nrow][ncol]==0){
                visited[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
    }
    
}

int main(){
    vector<vector<int>> graph = {{0, 1, 1, 0},
                                 {0, 0, 1, 0},
                                 {0, 0, 0, 0},
                                 {1, 0, 1, 1}};
    

    int n = graph.size();
    int m = graph[0].size();
    int counter = 0;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(visited[row][col]==0 and graph[row][col]==1){
                numberOfIslands(row,col,graph,visited);
                counter++;
            }
        }
    }
    cout<<"No Of Islands is:"<<counter<<endl;
    return 0;
}
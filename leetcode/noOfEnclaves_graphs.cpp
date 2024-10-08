class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &grid, vector<vector<int>> &vis){
        int r[] = {-1,1,0,0}; //up down left right
        int c[] = {0,0,-1,1};

        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nrow = row+r[i];
            int ncol = col+c[i];

            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid,vis);
            }
        }

        for(int i=0; i<m; i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid,vis);
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

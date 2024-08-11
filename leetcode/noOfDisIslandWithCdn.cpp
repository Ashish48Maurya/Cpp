class Solution {
  public:
    void dfs(int row,int col, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<pair<int,int>> &vec, int &rootRow, int &rootCol){
        int delrow[] = {-1,1,0,0}; //u d l r;
        int delcol[] = {0,0,-1,1}; //u d l r;
        vis[row][col] = 1;
        vec.push_back({row-rootRow , col-rootCol});
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if(nrow>=0 and ncol>=0 and nrow<grid.size() and ncol<grid[0].size() and grid[nrow][ncol]==1 and !vis[nrow][ncol])
            dfs(nrow,ncol,grid,vis,vec,rootRow,rootCol);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    vector<pair<int,int>> vec;
                    int rooti = i;
                    int rootj = j;
                    dfs(i,j,grid,vis,vec,rooti,rootj);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};
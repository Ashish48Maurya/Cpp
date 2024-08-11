class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis){
        int delrow[] = {-1,1,0,0}; //up down left right
        int delcol[] = {0,0,-1,1}; //up down left right
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int r = row+ delrow[i];
            int c = col+ delcol[i];
            if(r>=0 and c>=0 and r<board.size() and c<board[0].size() and !vis[r][c] and board[r][c]=='O'){
                dfs(r,c,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(); //row
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<m; i++){
            if(board[0][i]=='O' and !vis[0][i]){
                vis[0][i] = 1;
                dfs(0,i,board,vis);
            }
            if(board[n-1][i]=='O' and !vis[n-1][i]){
                vis[n-1][i] = 1;
                dfs(n-1,i,board,vis);
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0]=='O' and !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' and !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' and !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if(grid[i][j] == 1) {
                    visited[i][j] = 0;
                }
            }
        }

        int maxTime = 0;
        vector<int> rowDirection = {-1, 1, 0, 0}; // Up, Down, Left, Right
        vector<int> colDirection = {0, 0, -1, 1}; // Up, Down, Left, Right

        while(!q.empty()) {
            auto [pos, time] = q.front();
            q.pop();
            int row = pos.first;
            int col = pos.second;

            maxTime = max(maxTime, time);

            for(int i = 0; i < 4; i++) {
                int nrow = row + rowDirection[i];
                int ncol = col + colDirection[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        // Check if there are still fresh oranges left
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visited[i][j] != 2) {
                    return -1;
                }
            }
        }
        return maxTime;
    }
};
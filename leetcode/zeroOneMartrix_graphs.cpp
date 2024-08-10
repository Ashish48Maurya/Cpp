class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 0;
                    ans[i][j] = 0;
                }
            }
        }

        int row[] = {-1, 1, 0, 0}; // top bottom left right
        int col[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            q.pop();

            // Explore the 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + row[i];
                int ncol = c + col[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == -1) {
                    q.push({{nrow, ncol}, val + 1});
                    visited[nrow][ncol] = 0;
                    ans[nrow][ncol] = val + 1;
                }
            }
        }

        return ans;
    }
};
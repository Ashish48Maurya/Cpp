class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int prevCol = image[sr][sc];

        if (prevCol == color) return image;

        vector<vector<int>> visited(n, vector<int>(m));

        queue<pair<int, int>> q;
        q.push({sr, sc});

        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = image[i][j];
            }
        }

        vector<int> row = {-1, 1, 0, 0};
        vector<int> col = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            visited[r][c] = color;
            // image[sr][sc] = color;

            for (int i = 0; i < 4; ++i) {
                int nrow = r + row[i];
                int ncol = c + col[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == prevCol) {
                // if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == prevCol) {
                    q.push({nrow, ncol});
                }
            }
        }

        return visited;
    }
};
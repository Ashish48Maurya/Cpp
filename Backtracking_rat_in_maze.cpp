#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

void solve(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<string> &path, string ans)
{
    if (x == n - 1 && y == n - 1)
    {
        path.push_back(ans);
        return;
    }

    visited[x][y] = 1;

    // For Upward Move
    if (isSafe(x - 1, y, n, maze, visited))
    {
        solve(x - 1, y, n, maze, visited, path, ans + 'U');
    }

    // For Downward Move
    if (isSafe(x + 1, y, n, maze, visited))
    {
        solve(x + 1, y, n, maze, visited, path, ans + 'D');
    }

    // For Leftward Move
    if (isSafe(x, y - 1, n, maze, visited))
    {
        solve(x, y - 1, n, maze, visited, path, ans + 'L');
    }

    // For Rightward Move
    if (isSafe(x, y + 1, n, maze, visited))
    {
        solve(x, y + 1, n, maze, visited, path, ans + 'R');
    }

    visited[x][y] = 0;
}

int main()
{
    int n = 4;

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 1},
                                {0, 1, 1, 1}};

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> path;

    int srcx = 0;
    int srcy = 0;
    string ans = "";
    solve(srcx, srcy, n, maze, visited, path, ans);

    for (auto element : path)
    {
        cout << element << " ";
    }
    return 0;
}
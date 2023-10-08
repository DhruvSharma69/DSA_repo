#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &maze)
{
    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] != 1 && maze[x][y] == 1)
        return true;

    return false;
}

void solve(vector<vector<int>> &maze, int n, vector<string> &allPaths, vector<vector<int>> &visited, int x, int y, string singlePath)
{
    if (x == n - 1 && y == n - 1)
    {
        allPaths.push_back(singlePath);
        return;
    }

    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, 1, -1, 0};
    char dir[] = {'D', 'R', 'L', 'U'};

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int tempx = x + dx[i];
        int tempy = y + dy[i];

        if (check(tempx, tempy, n, visited, maze))
        {
            x = tempx;
            y = tempy;
            singlePath.push_back(dir[i]);
            solve(maze, n, allPaths, visited, x, y, singlePath);
            // Backtrack
            x -= dx[i];
            y -= dy[i];
            singlePath.pop_back();
        }
    }

    visited[x][y] = 0;
}

vector<string> getPaths(vector<vector<int>> &maze, int n)
{
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return {};

    vector<string> allPaths;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int x = 0, y = 0;
    string singlePath = "";
    solve(maze, n, allPaths, visited, x, y, singlePath);
    return allPaths;
}

int main()
{
    int n = 2;
    vector<vector<int>> maze(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            maze[i][j] = k;
        }
    }

    vector<string> ans = getPaths(maze, n);
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}

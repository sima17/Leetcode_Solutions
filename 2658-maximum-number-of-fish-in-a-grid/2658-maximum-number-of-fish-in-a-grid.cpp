class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        q.push({i, j});
        int fish = grid[i][j];
        grid[i][j] = 0;

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto d : dir) {
                int a = x + d[0], b = y + d[1];
                if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b]) {
                    q.push({a, b});
                    fish += grid[a][b];
                    grid[a][b] = 0;
                }
            }
        }
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mxFish = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    mxFish = max(mxFish, bfs(i, j, grid));
        return mxFish;
    }
};
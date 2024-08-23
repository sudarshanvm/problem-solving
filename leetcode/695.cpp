//problem: https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n,
             vector<int>& path) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return;

        grid[r][c] = 0;
        path.push_back(grid[r][c]);
        vector<int> rows = {1, -1, 0, 0};
        vector<int> cols = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int x = r + rows[i];
            int y = c + cols[i];

            dfs(grid, x, y, m, n, path);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    vector<int> path;
                    dfs(grid, i, j, m, n, path);
                    int temp = path.size();
                    res = max(res, temp);
                }
            }
        }

        return res;
    }
};

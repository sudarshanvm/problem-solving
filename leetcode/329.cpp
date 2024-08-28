// problem: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>>& matrix, int x, int y,
             vector<vector<int>>& dp) {
        
        if(dp[x][y])
            return dp[x][y];

        vector<int> rows = {1, -1, 0, 0};
        vector<int> cols = {0, 0, 1, -1};

        int maxlen = 1;
        for (int i = 0; i < 4; i++) {
            int r = x + rows[i];
            int c = y + cols[i];

            if(r>=0 && c>=0 && r<matrix.size() && c<matrix[0].size() &&  matrix[r][c] > matrix[x][y])
                maxlen = max(maxlen,1+dfs(matrix, r, c, dp));
        }

        return dp[x][y] = maxlen;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int res = dfs(matrix, i, j, dp);
                ans = max(ans,res);
            }
        }

        return ans;
    }
};

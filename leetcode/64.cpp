//problem: https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size(), n=grid[0].size();
        vector< vector<int> > sum(grid.begin(), grid.end());

        for(int i=1;i<m;i++)
            sum[i][0] += sum[i-1][0];

        for(int j=1;j<n;j++)
            sum[0][j] += sum[0][j-1];

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                sum[i][j] = grid[i][j] + min(sum[i-1][j], sum[i][j-1]);

        return sum[m-1][n-1];
        
    }
};

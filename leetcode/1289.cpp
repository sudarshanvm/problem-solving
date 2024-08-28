// problem: https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int m=grid.size(), n=grid[0].size();
        vector< vector<int> > dp(m,vector<int> (n,INT_MAX));

        for(int j=0;j<n;j++)
            dp[0][j] = grid[0][j];

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp = INT_MAX;
                for(int k=0;k<n;k++)
                    if(k!=j)
                        temp = min(temp,dp[i-1][k]);
                dp[i][j] = min(dp[i][j],temp+grid[i][j]);
            }
        }

        int res=INT_MAX;
        for(int j=0;j<n;j++)
            res=min(res,dp[m-1][j]);

        return res;
        
    }
};

/*
dp[i][j] = dp[i-1][j] or grid[i][j]+ dp[i-1][y] such that dp[i-1][y], dp[i-1][ y] is lowest in that row
*/

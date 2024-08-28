// problem: https://leetcode.com/problems/minimum-falling-path-sum/?envType=problem-list-v2&envId=55ac4kuc
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int> > dp(m+1,vector<int> (n+1,INT_MAX));

        for(int j=0;j<n;j++)
            dp[0][j] = matrix[0][j];


        int res = INT_MAX;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp1 = j>0?dp[i-1][j-1]:INT_MAX;
                int temp2 = j<n-1?dp[i-1][j+1]:INT_MAX;
                int temp3 = dp[i-1][j];

                int temp = min(temp1,min(temp2,temp3));
                dp[i][j] = matrix[i][j] + min(dp[i][j],temp);
            }
        }

        for(int j=0;j<n;j++)
            res = min(res,dp[m-1][j]);

        return res;
        
    }
};

/*

dp[i][j] = min(dp[i-1][j+1], dp[i-1][j-1],dp[i-1][j]) + matrix[i][j];

*/

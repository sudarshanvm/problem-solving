// problem: https://leetcode.com/problems/triangle/?envType=problem-list-v2&envId=55ac4kuc
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res=INT_MAX;
        int n=triangle.size();
        vector< vector<int> > dp(n);
        for(int i=0;i<n;i++)
            dp[i] = vector<int> (triangle[i].size(),INT_MAX);

        dp[0][0] = triangle[0][0];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                int temp1 = (j < triangle[i - 1].size()) ? dp[i - 1][j] : INT_MAX;
                int temp2 = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int temp = min(temp1,temp2);
                dp[i][j] = temp + triangle[i][j];
            }
                
        }

        for(int j=0;j<triangle[n-1].size();j++)
            res = min(res,dp[n-1][j]);
        return res;
    }
};
/*
dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
*/

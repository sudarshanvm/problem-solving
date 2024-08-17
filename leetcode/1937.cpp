//problem: https://leetcode.com/problems/maximum-number-of-points-with-cost/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int m=points.size(), n=points[0].size();
        vector< vector<long long> > dp(m, vector<long long> (n,0));

        vector<long long> left(n,0);
        vector<long long> right(n,0);

        for(int j=0;j<n;j++)
        {
            dp[0][j] = points[0][j];
        }

        for(int i=1; i<m; i++)
        {
            int pr = i-1;
            left[0] = dp[pr][0];
            for(int j=1;j<n;j++)
                left[j] = max(left[j-1]-1, dp[pr][j]);

            right[n-1] = dp[pr][n-1];
            for(int j=n-2;j>=0;j--)
                right[j] = max(right[j+1]-1, dp[pr][j]);

            for(int j=0;j<n;j++)
                dp[i][j] = points[i][j] + max(left[j], right[j]);

        }

        long long res = LLONG_MIN;

        for(int j=0;j<n;j++)
            res = max(res, dp[m-1][j]);

        return res;
    }
};

//https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        
        vector<int>dp(n+1,n);
        dp[0]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;(long long)j*j<=i;j++)
            {
                int sq = j*j;
                if(i-sq<0)
                    break;
                dp[i] = min(dp[i],dp[i-sq]+1);
            }
        }
        return dp[n];
    }
};
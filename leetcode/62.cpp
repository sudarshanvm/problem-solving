//problem : https://leetcode.com/problems/unique-paths/
class Solution {
public:

    int dp[101][101] = {0};

    int solve(int x, int y, int m, int n)
    {
        if(x>=m || y>= n)
            return 0;

        if(x==m-1 && y==n-1)
            return 1;

        if(dp[x][y])
            return dp[x][y];a

        return dp[x][y] = solve(x+1,y,m,n) + solve(x, y+1, m,n);
    }

    int uniquePaths(int m, int n) {
        if(m<=1 || n<=1)
            return 1;

        return solve(0,0,m,n);
    }
};

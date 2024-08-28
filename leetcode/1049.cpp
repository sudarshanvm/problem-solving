// problem: https://leetcode.com/problems/last-stone-weight-ii/?envType=problem-list-v2&envId=55ac4kuc
class Solution {
public:
    int sum = 0;
    int dp[31][3001];
    int solve(int x, int total, vector<int> stones) {
        if (x == stones.size() || total >= sum / 2)
            return abs(total - (sum - total));

        if (dp[x][total] != -1)
            return dp[x][total];

        return dp[x][total] = min(solve(x + 1, total, stones),
                                  solve(x + 1, total + stones[x], stones));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        for (auto stone : stones)
            sum += stone;
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, stones);
    }
};


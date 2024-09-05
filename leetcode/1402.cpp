// https://leetcode.com/problems/reducing-dishes/
class Solution {
public:

    int solve(vector<vector<int>>& dp, int idx, int time, const vector<int>& s) {
        if (idx == s.size()) {
            return 0;
        }
        
        if (dp[idx][time] != INT_MIN) {
            return dp[idx][time];
        }
        
        int take = s[idx] * time + solve(dp, idx + 1, time + 1, s);
        
        int notTake = solve(dp, idx + 1, time, s);

        dp[idx][time] = max(take, notTake);
        return dp[idx][time];
    }

    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(),s.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, INT_MIN));
        return solve(dp, 0, 1, s);  // Start time at 1 as per problem statement
    }
};

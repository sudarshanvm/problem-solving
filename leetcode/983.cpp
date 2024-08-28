// problem: https://leetcode.com/problems/minimum-cost-for-tickets/?envType=problem-list-v2&envId=50vlu3z5
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int max_day = days.back();
        
        vector<int> dp(max_day + 1, INT_MAX);
        dp[0] = 0; 

        vector<bool> travel_days(max_day + 1, false);
        for (int day : days) {
            travel_days[day] = true;
        }
        
        for (int i = 1; i <= max_day; ++i) {
            if (travel_days[i]) {
                dp[i] = dp[i - 1] + costs[0];
                
                if (i >= 7) {
                    dp[i] = min(dp[i], dp[i - 7] + costs[1]);
                } else {
                    dp[i] = min(dp[i], costs[1]);
                }
                
                if (i >= 30) {
                    dp[i] = min(dp[i], dp[i - 30] + costs[2]);
                } else {
                    dp[i] = min(dp[i], costs[2]);
                }
            } else {
                dp[i] = dp[i - 1];
            }
        }
        
        return dp[max_day];
    }
};

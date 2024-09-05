// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    vector<vector<bool>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)  
            return false;

        int target = sum / 2;
        dp = vector<vector<bool>>(nums.size()+1, vector<bool>(target + 1, false));

        int n=nums.size();
        for(int i=0;i<n;i++)
            dp[i][0]=1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                bool take = 0;
                if(j>=nums[i-1])
                    take = dp[i-1][j-nums[i-1]];
                bool notTake = dp[i-1][j];
                dp[i][j]= take || notTake;
            }
        }

        return dp[n-1][target];
    }
};

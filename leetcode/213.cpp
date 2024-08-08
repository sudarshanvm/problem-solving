//problem: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:

    int solve(vector<int> a)
    {
        vector<int> dp(a.size()+1);
        dp[0] = 0;
        dp[1] = a[0];
        for(int i=2;i<=a.size();i++)
            dp[i] = max(dp[i-1],dp[i-2]+a[i-1]);

        return dp[a.size()];
    }

    int rob(vector<int>& nums) {

        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return nums[0];

        vector<int> a(nums.size()-1);
        vector<int> b(nums.size()-1);

        for(int i=0;i<nums.size()-1;i++)
        {    
            a[i] = nums[i];
            b[i] = nums[i+1];
        }

        int res1 = solve(a);
        int res2 = solve(b);

        return max(res1,res2);
    }
};

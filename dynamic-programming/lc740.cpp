//problem: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums)
            m[i]+=i;
        
        int n=nums.size();
        vector<int>dp(10001,0);
        if(n==1)
            return nums[0];
        dp[0]=m[0];
        dp[1]=m[1];

        for(int i=2;i<=10000;i++)
            dp[i]=max(dp[i-2]+m[i], dp[i-1]);

        return dp[10000];
    }
};

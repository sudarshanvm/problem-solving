//problem: https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n+1,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    res[i] = max(res[i],1+res[j]);
            }

            ans = max(ans,res[i]);
        }

        return ans;
    }
};

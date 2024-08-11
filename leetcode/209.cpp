//problem: https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0,l=0,r=0,ans=INT_MAX;
        while(r<nums.size())
        {
            sum+=nums[r++];
            if(sum>=s)
            {
                while(sum>=s)
                {
                    ans=min(ans,r-l);
                    sum-=nums[l++];
                }
            }
        }
            return ans==INT_MAX?0:ans;
    }
};

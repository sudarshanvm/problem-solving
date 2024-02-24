//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int meh=0;
        int msf=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(meh<0)
                meh=nums[i];
            else
                meh+=nums[i];
            if(msf<meh)
                msf=meh;
        }
        
        return msf;
    }
};
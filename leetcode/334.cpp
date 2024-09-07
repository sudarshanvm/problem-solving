// https://leetcode.com/problems/increasing-triplet-subsequence/
//variation of LIS (Longest Increasing Subsequence)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis;
        for(int i=0;i<n;i++)
        {
            int idx=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(idx==lis.size())
                lis.push_back(nums[i]);
            else
                lis[idx]=nums[i];
        }
        return lis.size()>2;
    }
};

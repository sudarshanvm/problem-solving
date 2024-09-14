// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int m=max_element(nums.begin(),nums.end())-nums.begin();
        int len=0,res=0;

        for(int i=m;i<nums.size();i++)
        {
            while(i<nums.size() && nums[i]==nums[m])
            {
                i++;
                len++;
            }

            res=max(res,len);
            len=0;
        }
        return res;
    }
};

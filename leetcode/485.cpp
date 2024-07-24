//problem: https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(), res=0, count=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                count++;
                res = max(res, count);
            }

            else
                count=0;
        }

        return res;
    }
};

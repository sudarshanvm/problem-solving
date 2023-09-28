//problem : https://leetcode.com/problems/max-consecutive-ones-ii/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, left=0, numzeros=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                numzeros++;
            if(numzeros==2)
            {
                while(numzeros>1)
                {
                    if(nums[left]==0)
                        numzeros--;
                    left++;
                }
            }
            res = max(res, i-left+1);
        }

        return res;
    }
};

// problem: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int res=0;
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int temp = nums[right]+nums[left];
            res = max(res,temp);
            left++;
            right--;
        }
        return res;
    }
};


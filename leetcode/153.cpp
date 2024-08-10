// problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0)
            return -1;

        if(nums.size()==1)
            return nums[0];
             
        if(nums[0]<nums[nums.size()-1])
            return nums[0];

        int low=0, high=nums.size(), mid;
        while(low<high)
        {
            mid = low + (high-low)/2;
            if(nums[mid]>=nums[0])
                low = mid+1;
            else
                high = mid;
        }

        return nums[low];

    }
};

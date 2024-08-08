//problem: https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int mid;
        if(target<nums[0]||target>nums[nums.size()-1])
            return -1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
};

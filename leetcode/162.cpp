//problem: https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0, high = nums.size()-1, mid;
        
        while(low<high)
        {
            mid = low + (high-low)/2;
            if(nums[mid]<nums[mid+1])
                low = mid+1;
            else
                high = mid;
        }

        return low;
            
    }
};
        

//--------------------------------------------------------------
//problem: https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0)
            return -1;

        if(nums.size()==1)
            return 0;

        for(int i=1;i<nums.size()-1;i++)
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                return i;

        return nums[0]>nums[1]?0:nums.size()-1;
            
    }
};

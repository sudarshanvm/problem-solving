//problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:

    int searchHelper(vector<int>& nums, int target, bool leftBias)
    {
        int low=0,high=nums.size()-1,mid;
        int i=-1;

        while(low<=high)
        {
            mid = low + (high-low)/2;

            if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else
            {
                i=mid;
                if(leftBias)
                    high = mid-1;
                else
                    low = mid+1;
                
            }
        }
        

        return i;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = searchHelper(nums,target,true);
        int last = searchHelper(nums,target,false);

        return {first,last};
        
    }
};


//-----------------------------------------
//problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first=-1, last=-1,low=0,high=nums.size(),mid;

        while(low<high)
        {
            mid = low + (high-low)/2;

            if(nums[mid] == target)
            {
                int i=mid;
                while(i>=0 && nums[i]==target)
                    i--;

                first = i+1;

                i=mid;
                while(i<nums.size() && nums[i]==target)
                    i++;
                
                last = i-1;

                return {first,last};
                
            }

            if(nums[mid] < target)
                low = mid+1;
            else
                high = mid;
        }
        

        return {first,last};
    }
};

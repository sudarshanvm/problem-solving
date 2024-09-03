// problem: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
class Solution {
public:

    int solve(vector<int> nums, int bound)
    {
        int res=0,count=0;
        for(auto num:nums)
        {
            if(num<=bound)
                count++;
            else
                count=0;
            res += count;
        }

        return res;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return solve(nums,right)-solve(nums,left-1);
    }
};


//-----------------
// problem: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int i=-1, j=0, n=nums.size(),lastvalidindex=-1,count=0;
        while(j<n)
        {
            if(nums[j]>right)
                i=j;
            if(nums[j]>=left && nums[j]<=right)
                lastvalidindex=j;
            if(lastvalidindex>i)
                count +=(lastvalidindex-i);
            j++;
        }
        return count;
    }
};


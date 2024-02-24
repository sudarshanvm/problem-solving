//problem: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:

    int solve(vector<int> &nums, int k)
    {
        int n=nums.size();
        int res=0;
        int left=0, right=0,count=0;
        while(right<n)
        {
            count += nums[right];
            while(left<n&&count>k)
            {
                count-=nums[left];
                left++;
            }
            right++;
            res+=right-left;

        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        int left=0,right=0,res=0;
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]%2;

        return solve(nums,k)-solve(nums,k-1);
    }
};
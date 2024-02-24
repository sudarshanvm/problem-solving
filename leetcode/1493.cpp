//problem: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        //count total number of 0s in array
        // left=0, right=n-1 if 0s>1 : if a[left]==0; left++; 0s--; else 0s? right-- 
        // do aboe loop while 0s>1
        //if no 0s in the beginnning then n-1
        int z=0;
        int n=nums.size();
        int left=0, right=0, lastzero=0;
        int res=0;

        for(int i=0;i<n;i++)
            if(nums[i]==0)
            {
                lastzero=i;
                right=i;
                z=0;
                break;
            }

        res=right-left;
        while(right<n)
        {
            if(nums[right]==0)
            {
                if(z==0)
                {
                    right++;
                    z=1;
                    continue;
                }
                left = lastzero+1;
                lastzero=right;
                
            }
            res=max(res,right-left);
            right++;
        }

        return res;
    }
};
//problem: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0, r=0;
        long sum=0, res=0;

        sort(nums.begin(), nums.end());

        while(r<n)
        {
            sum += nums[r];

            int window_size = r-l+1;
           
            while(l<=r && (long)window_size * nums[r] > k + sum)
            {    
                sum -= nums[l++];
                window_size -= 1;
            }

            res = max((int)res, r-l+1);
            r++;
        }

        return res;
    
    }
};

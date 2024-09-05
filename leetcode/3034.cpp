// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/?envType=problem-list-v2&envId=string-matching
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m=pattern.size(), n=nums.size(),j=0,count=0;
        for (int i = 0; i <= n - m; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                // Check boundary conditions to avoid out-of-bound errors
                if (i + j + 1 >= n) {
                    match = false;
                    break;
                }
                if (pattern[j] == 1 && nums[i + j] >= nums[i + j + 1]) {
                    match = false;
                    break;
                } 
                if (pattern[j] == 0 && nums[i + j] != nums[i + j + 1]) {
                    match = false;
                    break;
                } 
                if (pattern[j] == -1 && nums[i + j] <= nums[i + j + 1]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                count++;
            }
        }

        return count;
    }
};


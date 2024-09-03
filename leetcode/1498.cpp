// problem: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        long long mod = pow(10,9)+7;

        long long sum = 0;
        vector<long long> powerOfTwo(nums.size(), 1);
        for (int k = 1; k < nums.size(); ++k) {
            powerOfTwo[k] = (powerOfTwo[k - 1] * 2) % mod;
        }

        int i=0, j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]+nums[j]>target)
                j--;
            else
            {
                sum = (sum + powerOfTwo[j-i]) % mod;
                i++;
            }
        }

        return (int)sum%mod;
        
    }
};

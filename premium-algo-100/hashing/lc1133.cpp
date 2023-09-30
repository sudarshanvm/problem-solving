//problem : https://leetcode.com/problems/largest-unique-number/

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {

        int a[1001]={0};
        int res=-1;
        for(int i=0;i<nums.size();i++)
            a[nums[i]]++;
        for(int i=0;i<nums.size();i++)
            if(a[nums[i]]==1)
                res = max(res, nums[i]); 
        return res;
    }
};

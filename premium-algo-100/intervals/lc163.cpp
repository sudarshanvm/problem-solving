//problem: https://leetcode.com/problems/missing-ranges/

class Solution {
public:

    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>res;
        if(nums.size()==0)
            res.push_back({lower,upper});

        for(int i=0;i<nums.size();i++)
        {
            if(i==0&&lower<nums[i])
                res.push_back({lower,nums[i]-1});
            
            if(i>0&&nums[i]-nums[i-1]>1)
                res.push_back({nums[i-1]+1,nums[i]-1});
           
            if(i==nums.size()-1&&nums[i]<upper)
                res.push_back({nums[i]+1,upper});

        }
        return res;
    }
};

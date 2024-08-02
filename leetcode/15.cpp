//problem: https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mx=nums[0];
        vector< vector<int> >res;
        set <vector<int>>s;
        for(int i=0; i<n; i++)
        {
            int j=i+1, k=n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0)
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    k--;
                }
                else if(sum<0)
                    j++;
                else 
                    k--;
            }
        }
        for(auto x: s)
            res.push_back(x);
        return res;
    }   
};

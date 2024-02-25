//problem: https://leetcode.com/problems/count-complete-subarrays-in-an-array/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s;
        for(auto num:nums)
            s.insert(num);

        int n=nums.size();
        int k=s.size();
        int res=0;
        int count=0;
        

        for(int i=0;i<n;i++)
        {
            set<int>temp;
            for(int j=i;j<n;j++)
            {
                temp.insert(nums[j]);
                if(temp.size()==k)
                    res++;
            }
        }
            return res;
    }
};
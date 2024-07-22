//problem: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=company&envId=google&favoriteSlug=google-thirty-days
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> a(nums.begin(), nums.end());
        vector<int> res;
        multiset<int>s;

        sort(a.begin(), a.end());

        if(k>a.size())
            return vector<int> ();

        for(int i=nums.size()-k;i<nums.size();i++)
        {
            cout<<a[i]<<"-";
            s.insert(a[i]);
        }
            

        for(int i=0;i<nums.size();i++)
        {
            auto it = s.find(nums[i]);
            if(it!=s.end())
            {
                s.erase(it);
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};


//optimized using unordered_set whose average time complexity is O(n)
//problem: https://leetcode.com/problems/longest-consecutive-sequence/?envType=company&envId=google&favoriteSlug=google-three-months

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        if(n<=1)
            return n;

        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        int count=1;

        for(auto num:s)
        {
            if(s.count(num-1))
                continue;
            while(s.count(num+1))
            {
                num++;
                count++;
                
            }
            res = max(res, count);
            count=1;
        }

        return res;

    }
};
//------------------------------------------------------------------------------------------------------------------------------

//problem: https://leetcode.com/problems/longest-consecutive-sequence/?envType=company&envId=google&favoriteSlug=google-three-months

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        if(n<=1)
            return n;

        sort(nums.begin(), nums.end());

        int left=0, right=1;
        int res=1,dups=0;

        while(right<n)
        {
            while(right<n and nums[right]-nums[right-1]<=1)
            {
                if(nums[right]==nums[right-1])
                    dups++;
                right++;
            }
                
            res = max(res,right-left-dups);
            left=right++;
            dups=0;
        }

        return res;

    }
};

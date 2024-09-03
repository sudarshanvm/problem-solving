// problem: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
typedef pair<int,int> pi;
class Solution {
public:

    int countPairs(vector<int>nums, int mid)
    {
        int count=0,left=0;
        for(int right=0;right<nums.size();right++)
        {
            while(nums[right]-nums[left]>mid)
                left++;
            count += (right-left);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        sort(nums.begin(),nums.end());
        int left=0, right=nums[n-1]-nums[0];
        while(left<right)
        {
            int mid = left+(right-left)/2;
            int cp = countPairs(nums,mid);
            if(cp<k)
                left=mid+1;
            else 
                right=mid;
        }
        return left;
    }
};


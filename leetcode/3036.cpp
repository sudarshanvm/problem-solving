// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/?envType=problem-list-v2&envId=string-matching
class Solution {
public:

    vector<int> computeLPS(vector<int> pat)
    {
        int m=pat.size();
        vector<int> lps(m,0);
        int len=0,i=1;
        while(i<m)
        {
            if(pat[i]==pat[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                    len=lps[len-1];
            }
        }
        return lps;
    }

    int kmp(vector<int> nums, vector<int> pat)
    {
        int m=pat.size(), n=nums.size();
        int count=0;
        if(m>n)
            return count;

        vector<int> lps(m,0);
        lps = computeLPS(pat);

        int i=0,j=0;
        while((n-i)>=(m-j))
        {
            if(pat[j]==nums[i])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                count++;
                j=lps[j-1];
            }
            else if(pat[j]!=nums[i])
            {
                if(j==0)
                    i++;
                else
                    j = lps[j-1];
            }
        }
        return count;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m=pattern.size(), n=nums.size();
        vector<int> a(nums.size()-1);
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
                a[i]=1;
            else if(nums[i]==nums[i+1])
                a[i]=0;
            else 
                a[i]=-1;
        }
        return kmp(a,pattern);
    }
};

/*
[1,4,4,1,3,5,5,3] -> [1,0,-1,1,1,0,-1]
[1,2,3,4,5,6] -> [1,1,1,1,1]
*/

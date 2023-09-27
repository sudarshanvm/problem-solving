//problem : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    bool isValid(int* a, int k)
    {
        int count=0;
        for(int i=0;i<128;i++)
            if(a[i])
                count++;

        return count<=k;
    }

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size()<=k)
            return s.size();

        int a[128]={0};
        int left=0, res=0;

        for(int i=0;i<s.size();i++)
        {
            a[s[i]]++;
            if(isValid(a, k))
                res=max(res,i-left+1);
            else
            {
                while(!isValid(a, k))
                {
                    a[s[left]]--;
                    left++;
                }
            }
        }

        return res;
    }
};

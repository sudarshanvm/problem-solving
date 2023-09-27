//problem: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/

class Solution {
public:

    bool isValid(int* h)
    {   
        int count=0;
        for(int i=0;i<128;i++)
            if(h[i])
                count++;

        return count<=2;
    }

    int lengthOfLongestSubstringTwoDistinct(string s) {
        char c1,c2;
        int res = 0, last = 0;
        int h[128] = {0};
        for(int i=0; i<s.size(); i++)
        {
            h[s[i]]++;
            if(isValid(h))
                res = max(res,i-last+1);
            else
            {
                while(!isValid(h))
                {
                    h[s[last]]--;
                    last++;
                }
            }
        }

        return res;
    }
};

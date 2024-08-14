//problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[256] = {0};
        int res = 0, left = 0;
        for(int i=0;i<s.size();i++)
        {
            while(a[s[i]])
            {
                a[s[left]]--;
                left++;
            }
            a[s[i]]++;
            res = max(res, i-left+1);
        }
        return res;
    }
};

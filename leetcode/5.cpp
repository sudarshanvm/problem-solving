//problem: https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:

    bool ispalindrome(string s)
    {
        string p = s;
        reverse(p.begin(),p.end());
        return s==p;
    }

    string longestPalindrome(string s) {
        int l=0, r=0;
        if(s.size()<2)
            return s;

        string res;
        int ressize=0;
        for(int i=0;i<s.size();i++)
        {
            // if pal size is odd
                l = i;
                r = i;

            
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(r-l+1 > ressize)
                {
                    ressize = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }

        for(int i=0;i<s.size();i++)
        {
            // if pal size is even
                l = i;
                r = i+1;

            
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(r-l+1 > ressize)
                {
                    ressize = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }
        
        return res.size()==0?s.substr(0,1):res;
    }
};

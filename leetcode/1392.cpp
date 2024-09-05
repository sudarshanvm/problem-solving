// problem: https://leetcode.com/problems/longest-happy-prefix/?envType=problem-list-v2&envId=string-matching
// KMP algorithm
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        if(n==0)
            return "";
        
        vector<int> lps(n,0);
        lps[0] = 0;

        // loop calculates lps[i] for i = 1 to M-1
        int i = 1,len=0;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else // (pat[i] != pat[len])
            {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0,len);
    }
};

//problem: https://leetcode.com/problems/score-of-a-string/
class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        if(s.size()<2)
            return 0;
        for(int i=1;i<s.size();i++)
        {
            res += abs(s[i]-s[i-1]);
        }

        return res;
    }
};

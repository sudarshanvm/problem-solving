//problem : https://leetcode.com/problems/single-row-keyboard/description/

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int n=keyboard.size(),res=0;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
            m[keyboard[i]] = i;
        int prev = 0;
        for(int i=0;i<word.size();i++)
            {
                res += abs(m[word[i]] - prev);
                prev = m[word[i]];
            }
        return res;
    }
};

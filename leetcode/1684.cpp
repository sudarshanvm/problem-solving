// https://leetcode.com/problems/count-the-number-of-consistent-strings/
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>s(allowed.begin(),allowed.end());
        int count=0;
        for(string word:words)
        {
            bool flag=true;
            for(char c:word)
                if(s.find(c)==s.end())
                {
                    flag=false;
                    break;
                }
            if(flag)
                count++;
        }

        return count;
    }
};

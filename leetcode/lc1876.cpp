class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        

        for(int i=0;i<s.size();i++)
        {
            if(i+2>s.size()-1)
                break;
            if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2])
                count++;
        }
        return count;
    }
};
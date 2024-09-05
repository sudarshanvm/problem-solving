// problem : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=problem-list-v2&envId=string-matching

class Solution {
public:
    bool ispns(string pat, string txt)
    {
        int m=pat.size(),n=txt.size();
        if(m>n)
            return false;

        for(int i=0;i<m;i++)
            if(pat[i]!=txt[i])
                return false;

        for(int j=0;j<m;j++)
            if(pat[m-1-j]!=txt[n-1-j])
                return false;

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0,n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(ispns(words[i],words[j]))
                    count++;
            }
        }
        return count;
    }
};

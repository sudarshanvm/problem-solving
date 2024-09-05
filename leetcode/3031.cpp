// https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/?envType=problem-list-v2&envId=string-matching
class Solution {
public:
    vector<int> computeLPS(string pat)
    {
        int m=pat.size();
        vector<int> lps(m,0);
        int i=1,len=0;
        while(i<m)
        {
            if(pat[i]==pat[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                    len = lps[len-1];
            }
        }
        return lps;
    }

    int minimumTimeToInitialState(string word, int k) {
        vector<int> lps = computeLPS(word);
        int len = lps.back(), n=word.size();

        while(len>0 && (n-len)%k!=0)
            len = lps[len-1];

        return ceil((float)(n-len)/k);
    }
};

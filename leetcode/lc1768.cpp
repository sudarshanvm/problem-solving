class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i=0;
        int m=word1.size(), n=word2.size();
        if(m>n)
        {
            while(i<n)
            {
                res += word1[i];
                res += word2[i++];
            }
            while(i<m)
                res += word1[i++];
        }
        else
        {
            while(i<m)
            {
                res += word1[i];
                res += word2[i++];
            }
            while(i<n)
                res += word2[i++];
        }

        return res;
    }
};
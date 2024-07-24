//problem: https://leetcode.com/problems/longest-common-prefix/?envType=company&envId=google&favoriteSlug=google-three-months

class Solution {
public:

    int min(int a, int b)
    {
        return a<=b?a:b;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
        int n=strs[0].size();
        for(int i=0;i<strs.size();i++)
            n = min(n,strs[i].size());


        string res="";
        for(int i=0;i<n;i++)
        {
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(ch != strs[j][i])
                    return res;
            }

            res += ch;
        }

        return res;
    }
};

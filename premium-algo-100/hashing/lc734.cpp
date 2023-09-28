//problem : https://leetcode.com/problems/sentence-similarity/description/

class Solution {
public:
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& sp) {
        int m=s1.size(), n=s2.size();

        if(m!=n)
            return false;

        if(sp.size()==0)
            return true;

        unordered_map<string,bool>h;

        for(int i=0;i<sp.size();i++)
        {
            string s1 = sp[i][0] + "," + sp[i][1];
            string s2 = sp[i][1] + "," + sp[i][0];
            h[s1]=true;
            h[s2]=true;
        }

        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i] || (h.count(s1[i]+","+s2[i]) || (h.count(s2[i]+","+s1[i]))))
                continue;
            return false;
        }

        return true;

    }
};

//problem : https://leetcode.com/problems/find-permutation/

class Solution {
public:

    vector<int> findPermutation(string s) {
        vector<int> res;
        
        int nexti[s.size()];
        int lasti = s.size();
        for(int i=s.size()-1;i>=0;i--)
        {
            nexti[i] = lasti;
            if(s[i]=='I')
                lasti = i;
        }

        int numi,numd;
        if(s[0]=='I')
        {
            numi=1;
            numd=1;
        }
        else
        {
            numd=2;
            numi=2;
        }

        res.push_back(numi);
        int min_ele=numi;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='D')
            {
                res.push_back(--numd);
                min_ele = min(min_ele,numd);
            }
                
            else
            {
                numi += nexti[i]-i;
                res.push_back(numi);
                numd = numi;
                min_ele = min(min_ele,numi);
            }
        }

        for(int i=0;i<res.size();i++)
            res[i]=res[i]+abs(min_ele-1);
        return res;
    }
};

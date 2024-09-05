// problem: https://leetcode.com/problems/repeated-substring-pattern/?envType=problem-list-v2&envId=string-matching
class Solution {
public:

    bool rabin_karp_match(string txt, string pat)
    {
        if(txt.size()<pat.size())
            return false;
        int d=26,mod=11;
        int p=0,t=0,h=1,i,j;
        int n=txt.size(),m=pat.size();
        for(i=0;i<m;i++)
        {
            h = (h*d)%mod;
            p = (p*d + pat[i])%mod;
            t = (t*d + txt[i])%mod;
        }

        for(i=0;i<=n-m;i++)
        {
            if(p==t)
            {
                for(j=0;j<m;j++)
                    if(txt[i+j]!=pat[j])
                        break;
                if(j==m)
                    return true;
            }

            if(i<n-m)
            {
                int t_ = t-txt[i]*h;
                t = (t_ * d + txt[i+m])%mod;
                if(t<0)
                    t+=mod;
            }
        }
        return false;
    }

    string generate(string pat, int m)
    {
        string s="";
        while(m--)
            s+=pat;
        return s;
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> count(26, 0);
        if(s.size()<=1)
            return false;
        
        int n=s.size();
        string pat="";
        for(int i=0;i<n/2;i++)
        {
            pat+=s[i];
            if(rabin_karp_match(generate(pat,n/(i+1)),s))
                return true;
        }
        return false;
    }
};

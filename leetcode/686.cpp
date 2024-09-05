// problem: https://leetcode.com/problems/repeated-string-match/
#define d 26
#define q 11
class Solution {
public:

    bool find_pattern(string txt, string pat)
    {
        int m=pat.size(),n=txt.size();
        if(n<m)
            return false;

        int p=0,t=0,h=1,i,j;

        for(i=0;i<m-1;i++)
            h = (d*h)%q;
        
        //calc initial p,t
        for(i=0;i<m;i++)
        {
            p = (d*p + pat[i])%q;
            t = (d*t + txt[i])%q;
        }

        for(i=0;i<=n-m;i++)
        {
            if(p==t)
            {
                for(j=0;j<m;j++)
                    if(pat[j]!=txt[i+j])
                        break;
                if(j==m)
                    return true;
            }

            
            if(i<n-m)
            {
                int t_ = t - txt[i]*h;
                t = (d* t_ + txt[i+m])%q;
                if(t<0)
                    t += q;
            }
                

        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string s1="";
        int count=0;

        set<char>set1(a.begin(),a.end()),set2(b.begin(),b.end());
        for(auto b_char:set2)
            if(set1.find(b_char)==set1.end())
                return -1;

        while(s1.size()<=2*(a.size()+b.size()))
        {
            if(find_pattern(s1,b))
                return count;
            count++;
            s1 += a;
        }
        return -1;
    }
};

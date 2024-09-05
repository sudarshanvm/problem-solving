// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/?envType=problem-list-v2&envId=string-matching
class Solution {
public:

    vector<int> rabinKarp(string txt, string pat)
    {
        int m=pat.size(),n=txt.size();
        vector<int> indices;
        if(m>n)
            return {};
        
        long long d=26;
        long long mod=1e9+7;
        long long p=0,t=0,h=1;
        for(int i=0;i<m-1;i++)
            h = (h*d)%mod;
        
        for(int i=0;i<m;i++)
        {
            p = (p*d+pat[i])%mod;
            t=(t*d+txt[i])%mod;
        }

        int i,j;
        for(i=0;i<=n-m;i++)
        {
            if(p==t)
            {
                for(j=0;j<m;j++)
                {
                    if(pat[j]!=txt[i+j])
                        break;
                }
                if(j==m)
                    indices.push_back(i);
            }
            if(i<n-m)
            {
                long long t_= (t-txt[i]*h)%mod;
                t=(t_*d+txt[i+m])%mod;
                if(t<0)
                    t+=mod;
            }
        }
        return indices;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> a_indices = rabinKarp(s,a);
        vector<int> b_indices = rabinKarp(s,b);
        vector<int> res;
        for(int i=0;i<a_indices.size();i++)
        {
            for(int j=0;j<b_indices.size();j++)
            {
                if(abs(a_indices[i]-b_indices[j])<=k)
                {
                    res.push_back(a_indices[i]);
                    break;
                }
            }
            cout<<endl;
        }
        return res;
    }
};

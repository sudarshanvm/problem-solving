//problem: https://leetcode.com/problems/find-the-celebrity/description/?envType=study-plan-v2&envId=premium-algo-100


//----------------------------------------------------------
//TLE
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int>a(n,0);
        vector<int>b(n,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(knows(i,j)&&i!=j)
                {
                    a[i]++;
                    b[j]++;
                }


        int res=-1;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<"-"<<b[i]<<" ";
            
            if(a[i]==0)
            {
                if(flag)
                {
                    res = -1;
                    break;
                }
                else
                {
                    res = i;
                    flag = true;
                }
            }
        }

        if(res!=-1&&b[res]!=n-1)
            res = -1;
        return res;

    }
};

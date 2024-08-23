//problem: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ugly;
        unordered_map<long long, bool> vis;
        ugly.push_back(1);
        vis[1]=true;
        int i2=0, i3=0, i5=0;

        while(ugly.size()<n)
        {
            long long ugly2 = ugly[i2]*2;
            long long ugly3 = ugly[i3]*3;
            long long ugly5 = ugly[i5]*5;

            long long temp_ugly = min(ugly2, min(ugly3,ugly5));

            if(temp_ugly==ugly2)
                i2++;
            else if(temp_ugly==ugly3)
                i3++;
            else
                i5++;

            if(vis.find(temp_ugly)==vis.end())
            {    
                ugly.push_back(temp_ugly);
                vis[temp_ugly]=true;
            }

        }

        return ugly[n-1];
    }
};






//-----------------------
//https://leetcode.com/problems/ugly-number-ii/
#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {

        priority_queue<ll, vector<ll>, greater<ll> >pq;
        unordered_map<ll,int>m;
        pq.push(1);
        ll count=0,top;
        while(count<n)
        {
            top=pq.top();
            pq.pop();
            if(m[top]==0)
            {
                m[top]=1;
                pq.push(top*2);
                pq.push(top*3);
                pq.push(top*5);
                count++;
            }
        }

        return top;
    }
};

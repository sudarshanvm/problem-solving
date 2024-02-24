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

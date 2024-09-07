// https://leetcode.com/problems/russian-doll-envelopes/?envType=problem-list-v2&envId=binary-search&difficulty=HARD
class Solution {
public:
    static bool comp(vector<int>& a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> dp;
        for(int i=0;i<envelopes.size();i++)
        {
            int idx = lower_bound(dp.begin(),dp.end(),envelopes[i][1])-dp.begin();
            if(idx==dp.size())
                dp.push_back(envelopes[i][1]);
            else
                dp[idx]=envelopes[i][1];
        }
        return dp.size();
    }
};

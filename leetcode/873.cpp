// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
class Solution {
public:

    int solve(vector<int> &arr, unordered_map<int,int> &m, int i, int j, vector<vector<int> > &dp)
    {
        if(m.find(arr[i]+arr[j])==m.end())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=1+solve(arr,m,j,m[arr[i]+arr[j]],dp);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[arr[i]]=i;

        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(m.find(arr[i]+arr[j])!=m.end())
                {
                    int temp = 2 + solve(arr,m,i,j,dp);
                    res = max(res,temp);
                }
            }
        }
        return res;
    }
};


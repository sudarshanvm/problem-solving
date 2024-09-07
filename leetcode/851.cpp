// https://leetcode.com/problems/loud-and-rich/?envType=problem-list-v2&envId=topological-sort
class Solution {
public:

    int bfs(vector<vector<int> > &adj, vector<int> &quiet, int x)
    {
        unordered_set<int>vis;
        int n=quiet.size();
        queue<int> q;
        q.push(x);
        vis.insert(x);
        int res=INT_MAX,idx=n;
        while(!q.empty())
        {
            int top = q.front(); q.pop();
            if (quiet[top] < res) {
                res = quiet[top];
                idx = top;
            }

            for(auto nei:adj[top])
            {
                if(vis.find(nei)==vis.end())
                {
                    vis.insert(nei);
                    q.push(nei);
                }
            }
        }
        return idx;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n,-1);
        vector<vector<int> > adj(n,vector<int>());
        for(auto edge:richer)
        {
            int x=edge[0], y=edge[1];
            adj[y].push_back(x);
        }
        for(int i=0;i<n;i++)
            ans[i]=bfs(adj,quiet,i);

        return ans;
    }
};

// problem: https://leetcode.com/problems/find-eventual-safe-states/
class Solution {
public:

    bool dfs(int x, unordered_map<int,bool> &m, vector<vector<int>>& graph)
    {
        if(m.find(x)!=m.end())
            return m[x];

        m[x]=false;

        for(auto node: graph[x])
        {
            if(!dfs(node,m,graph))
                return false;
        }
        m[x]=true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,bool> m;
        vector<int> res;

        for(int i=0;i<n;i++)
            if(dfs(i,m,graph))
                res.push_back(i);

        return res;
    }
};

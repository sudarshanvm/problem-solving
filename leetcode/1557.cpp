// problem : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incoming(n,false);
        vector<int> res;
        for(auto edge: edges)
            incoming[edge[1]]=true;
        for(int i=0;i<n;i++)
            if(!incoming[i])
                res.push_back(i);
        return res;
    }
};




//------------------------------------------------------------------------
class Solution {
public:
void dfs(int node ,vector<int>adj[],int n,vector<int>&vis,set<int>&s)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(vis[i]==1&&s.find(i)!=s.end())
        {
            s.erase(s.find(i));
        }
        if(vis[i]==0)
        dfs(i,adj,n,vis,s);
    }
    
}
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& v) {
        vector<int>ans;
        set<int>s;
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<v.size();i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                // ans.push_back(i);
                s.insert(i);
                dfs(i,adj,n,vis,s);
            }
        }
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

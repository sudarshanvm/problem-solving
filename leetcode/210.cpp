//problem: https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    
    bool dfs(int s, vector<vector<int>>& adj, vector<bool> &vis, vector<bool> &instack, vector<int> &res)
    {
        if(instack[s])
            return true;

        if(vis[s])
            return false;

        vis[s]=true;
        instack[s]=true;
        
        for(auto node: adj[s])
        {
            if(dfs(node,adj,vis,instack,res))
                return true;
        }

        instack[s]=false;
        res.push_back(s);
        
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        for(auto edge: prerequisites)
            adj[edge[0]].push_back(edge[1]);

        vector<bool> vis(numCourses,false);
        vector<bool> instack(numCourses,false);
        
        vector<int> res;
        for(int i=0;i<numCourses;i++)
        {
            
            bool cycle = dfs(i,adj,vis,instack,res);
            if(cycle)
                return vector<int>();
        }
            
       return res;

    }
};

//problem: https://leetcode.com/problems/course-schedule/

class Solution {
public:

    bool dfs(int s, vector<vector<int>>& adj, vector<bool> &vis, vector<bool> &instack )
    {
        if(instack[s])
            return true;

        if(vis[s])
            return false;

        vis[s]=true;
        instack[s]=true;
        for(auto node: adj[s])
        {
            if(dfs(node,adj,vis,instack))
                return true;
        }

        instack[s]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses);
        vector<bool>inStack(numCourses);

        vector<vector<int> > adj(numCourses);

        for(auto edge: prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(dfs(i,adj,vis,inStack))
            {
                return false;
            }
        }

        return true;
    }
};

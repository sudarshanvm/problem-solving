//problem: https://leetcode.com/problems/find-if-path-exists-in-graph/

class UnionFind
{
    private:
        vector<int>root;
    
    public:
    
        UnionFind(int n)
        {
            for(int i=0;i<n;i++)
                root.push_back(i);
        }
    
        int find(int x)
        {
            if(x==root[x])
                return x;
            return root[x]=find(root[x]);
        }
    
        void unionSet(int x, int y)
        {
            int rx = find(x);
            int ry = find(y);
            
            if(rx!=ry)
                root[ry]=rx;
        }
    
        bool connected(int x, int y)
        {
            return find(x)==find(y);
        }
    
    
};

class Solution {
public:
    
    bool dfs(vector<vector<int>> graph, int source, int destination)
    {
        if(source==destination)
            return true;
        
        stack<int>s;
        vector<bool>vis(graph.size());
        
        s.push(source);
        vis[source]=true;
        
        while(!s.empty())
        {
            int cur = s.top();
            s.pop();
            vis[cur]=true;
            
            if(cur==destination)
                return true;
            
            for(auto nextnode:graph[cur])
            {
                if(!vis[nextnode])
                {
                    vis[nextnode]=true;
                    s.push(nextnode);
                }
            }
        }
        return false;
    }
        
    bool bfs(vector<vector<int>> graph, int source, int destination)
    {
        if(source==destination)
            return true;
        
        queue<int>q;
        vector<bool> vis(graph.size());
        q.push(source);
        vis[source]=true;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            vis[front]=true;
            
            if(front==destination)
                return true;
                
            for(auto nextnode:graph[front])
            {
                if(!vis[nextnode])
                {
                    vis[nextnode]=true;
                    q.push(nextnode);
                }
                    
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size()==0)
            return true;
        
        vector<vector<int>> g(n);
        for(auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        return dfs(g, source, destination);
        //return bfs(g, source, destination);
    }
};

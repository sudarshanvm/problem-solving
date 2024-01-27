//problem: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void dfs(vector<vector<int>> graph, int curnode, vector<int> &path, vector<vector<int> > &paths)
    {
        path.push_back(curnode);
        if(curnode==graph.size()-1)
        {
            paths.push_back(path);
            return;
        }
        
        for(auto nextnode:graph[curnode])
        {
            dfs(graph, nextnode, path, paths);
            path.pop_back();
        }
        
        return; 
    }
    
    void bfs(vector<vector<int>> graph, int curnode, vector<int> &path, vector<vector<int> > &paths)
    {
        queue< vector<int> > q;
        path.push_back(curnode);
        
        q.push(path);
        while(!q.empty())
        {
            vector<int> currentPath = q.front();
            q.pop();
            int node = currentPath.back();
            for (int nextNode : graph[node]) {
                vector<int> tmpPath(currentPath.begin(), currentPath.end());
                tmpPath.push_back(nextNode);
                if (nextNode == graph.size() - 1) {
                    paths.push_back(tmpPath);
                } else {
                    q.push(tmpPath);
                }
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if(graph.size()==0)
            return paths;
        
        vector<int>path;
        //dfs(graph, 0, path, paths);
        bfs(graph, 0, path, paths);
        
        return paths;
    }
};
